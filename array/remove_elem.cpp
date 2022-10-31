//
// Created by xianglong on 2022/10/29.
//
#include "remove_elem.h"
#include <string>

namespace remove_elem {
//    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//
//    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
//
//    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
    void Test() {
        try {
            Runner runner;
            runner.Runnable();
        } catch (std::out_of_range e) {
            std::cout << "单测执行失败" << std::endl;
            std::cout << e.what() << "下标访问越界" << std::endl;
        }
    }

    int ViolenceRemove::removeElement(std::vector<int> &nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums.at(i) != val) {
                continue;
            }
            // 如果发现重复，则通过移位删除，向前移位
            for (int j = i; j < size -1; j++) {
                nums[j] = nums[j + 1];
            }
            size--;
            i--; // 外层循环 有i++，因此这里要i--
        }
        return size;
    }

    std::string ViolenceRemove::type() const {
        return "暴力删除";
    }

    int TowPointerRemove::removeElement(std::vector<int> &nums, int val) {
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            ++fast;// 必须写在外层，不然会死循环
        }
        return slow;
    }

    std::string TowPointerRemove::type() const {
        return "快慢指针删除";
    }

    int OppoTowPointerRemove::removeElement(std::vector<int> &nums, int val) {
        int left = 0;
        int right = nums.size();
        right = right - 1;// 防止溢出
        while (left <= right) {
            // 找到左侧相等的元素
            while (left <= right && nums[left] != val) {
                ++left;
            }
            // 找到右侧不相等的元素
            while (left <= right && nums[right] == val) {
                --right;
            }
            if (left < right) {
                nums[left++] = nums[right--];
            }
        }
        return left;
    }

    std::string OppoTowPointerRemove::type() const {
        return "相向双指针删除( 改变元素相对位置 )";
    }

    Runner::Runner() {
        this->_problemDescription();
        this->_registerSearch(new ViolenceRemove);
        this->_registerSearch(new TowPointerRemove);
        this->_registerSearch(new OppoTowPointerRemove);
    }

    void Runner::Runnable() {
        std::vector<std::tuple<std::string, std::vector<int>, int, int >> cases = this->_productCase();
        for (auto r: this->_res) {
            if (r == nullptr) {
                continue;
            }
            for (auto v: cases) {
                std::string case_type;
                std::vector<int> element;
                int target, result;
                std::tie(case_type, element, target, result) = v;
                if (result != r->removeElement(element, target)) {
                    std::cout << "---------------------------------" << std::endl;
                    std::cout << "单测失败" << std::endl;
                    std::cout << "算法类型:" << r->type() << std::endl;
                    std::cout << "测试case:" << case_type << std::endl;
                    std::cout << "---------------------------------" << std::endl;
                    return;
                }
            }
            std::cout << "所有测试case通过: " << r->type() << std::endl;
        }
    }

    Runner::~Runner() {
        for (auto v: this->_res) {
            if (v != nullptr) {
                delete v;
                v = nullptr;
            }
        }
        // clear size
        this->_res.clear();
        // clear capacity
        std::vector<RemoveElement *>().swap(this->_res);
    }

    void Runner::_problemDescription() {
        std::cout << "给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。"
                  << std::endl;
        std::cout << "不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。" << std::endl;
        std::cout << "元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。" << std::endl;
        std::cout << "示例 : 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。"
                  << std::endl;
        std::cout << std::endl;
    }

    void Runner::_registerSearch(RemoveElement *re) {
        this->_res.push_back(re);
    }

    std::vector<std::tuple<std::string, std::vector<int>, int, int>> Runner::_productCase() {
        std::vector<std::tuple<std::string, std::vector<int>, int, int>> result;
        // 空数组
        result.push_back(std::make_tuple("空数组", std::vector<int>{}, 1, 0));
        // 单个元素（不删除）
        result.push_back(std::make_tuple("单个元素（不删除）", std::vector<int>{1}, 2, 1));
        // 单个元素（删除）
        result.push_back(std::make_tuple("单个元素（删除）", std::vector<int>{1}, 1, 0));
        // 多个元素（删除）
        result.push_back(std::make_tuple("多个元素（删除）", std::vector<int>{1, 2, 3, 4, 5, 2, 4, 2, 2}, 2, 5));
        // 多个元素（不删除）
        result.push_back(std::make_tuple("多个元素（不删除）", std::vector<int>{1, 2, 3, 4, 5, 2, 4, 2, 2}, 10, 9));
        return result;
    }
} // namespace remove_elem
