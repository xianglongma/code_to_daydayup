//
// Created by xianglong on 2022/10/29.
//

#include "array_search.h"

namespace array_search {
    // 1.暴力搜索 O(n)
    int ViolenceSearch::search(std::vector<int> &nums, int target) {
        // nums.size(), 底层是无符号整形，减一有可能会越界
        // std::cout <<   nums.size() - 1 << std::endl;
        // for (int i = 0; i <= nums.size() - 1; i++) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == target) {
                return i;
            }
        }
        return -1;
    }

    std::string ViolenceSearch::type() {
        return "暴力搜索";
    }

    int OppositeDirectionBinarySearch::search(std::vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums.at(middle) == target) {
                return middle;
            } else if (nums.at(middle) > target) {
                right--;
            } else if (nums.at(middle) < target) {
                left++;
            }
        }
        return -1;
    }

    std::string OppositeDirectionBinarySearch::type() {
        return "相向双指针二分查找";
    }

    int ClassicalBinarySearch::search(std::vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums.at(middle) == target) {
                return middle;
            } else if (nums.at(middle) > target) {
                right = middle - 1;
            } else if (nums.at(middle) < target) {
                left = middle + 1;
            }
        }
        return -1;
    }

    std::string ClassicalBinarySearch::type() {
        return "经典的二分查找";
    }

    // 构造跑runner
    Runner::Runner() {
        this->_registerSearch(new ViolenceSearch);
        this->_registerSearch(new OppositeDirectionBinarySearch);
        this->_registerSearch(new ClassicalBinarySearch);
        for (auto v: this->_searchers) {
            if (v != nullptr) {
                std::cout << v->type() << " 初始化成功！" << std::endl;
            }
        }
    }

    void Runner::_registerSearch(Search *search) {
        if (search != nullptr) {
            this->_searchers.push_back(search);
        }
    }
    std::vector<std::tuple<std::string, std::vector < int>, int, int>>

    Runner::_productCase() {
        std::vector < std::tuple < std::string, std::vector < int >, int, int >> result;
        // 空数组
        result.push_back(std::make_tuple("空数组", std::vector < int > {}, 1, -1));
        // 单个元素
        result.push_back(std::make_tuple("单个元素", std::vector < int > {1}, 1, 0));
        // 奇数个元素
        result.push_back(std::make_tuple("奇数个元素", std::vector < int > {-1, 0, 1, 2, 3}, 1, 2));
        // 奇数个元素左边界
        result.push_back(std::make_tuple("奇数个元素左边界", std::vector < int > {-1, 0, 1, 2, 3}, -1, 0));
        // 奇数个元素右边界
        result.push_back(std::make_tuple("奇数个元素右边界", std::vector < int > {-1, 0, 1, 2, 3}, 3, 4));
        // 偶数个元素
        result.push_back(std::make_tuple("偶数个元素", std::vector < int > {-1, 0, 1, 2, 3, 5}, 1, 2));
        // 偶数个元素左边界
        result.push_back(std::make_tuple("偶数个元素左边界", std::vector < int > {-1, 0, 1, 2, 3, 5}, -1, 0));
        // 偶数个元素右边届
        result.push_back(std::make_tuple("偶数个元素右边届", std::vector < int > {-1, 0, 1, 2, 3, 5}, 5, 5));
        return result;
    }

    void Runner::Runnable() {
        std::vector < std::tuple < std::string, std::vector < int >, int, int >> cases = this->_productCase();
        for (auto r: this->_searchers) {
            if (r == nullptr) {
                continue;
            }
            for (auto v: cases) {
                std::string case_type;
                std::vector<int> element;
                int target, result;
                std::tie(case_type, element, target, result) = v;
                if (result != r->search(element, target)) {
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
        for (auto v: this->_searchers) {
            if (v != nullptr) {
                delete v;
                v = nullptr;
            }
        }
        this->_searchers.clear(); // clear  this->_searchers.size() 为零 但是this->_searchers.capacity()不为零；空间并未完全释放
        // std::cout << "size:" << this->_searchers.size() << " capacity:" << this->_searchers.capacity() << std::endl;
        std::vector<Search *>().swap(this->_searchers);
        // std::cout << "size:" << this->_searchers.size() << " capacity:" << this->_searchers.capacity() << std::endl;
    }
} // namespace array_search
