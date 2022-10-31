//
// Created by xianglong on 2022/10/29.
//

#ifndef CODE_TO_DAYDAYUP_ARRAY_SEARCH_H
#define CODE_TO_DAYDAYUP_ARRAY_SEARCH_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <tuple>
// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
namespace array_search {
    class Search {
    public:
        virtual int search(std::vector<int> &nums, int target) = 0;

        virtual std::string type() = 0;
    };

    // 1.暴力搜索
    class ViolenceSearch : public Search {
    public:
        int search(std::vector<int> &nums, int target);

        std::string type();
    };

    // 2.二分查重 O(log2n)； 两边向中间，类似于 相向双指针 的思路
    class OppositeDirectionBinarySearch : public Search {
    public:
        int search(std::vector<int> &nums, int target);

        std::string type();
    };

    // 3.经典的二分查找 O(log2n);
    class ClassicalBinarySearch : public Search {
    public:
        int search(std::vector<int> &nums, int target);

        std::string type();
    };

    class Runner {
    public:
        // 构造函数
        Runner();

        // 执行测试
        void Runnable();
        ~Runner();

    private:
        // 测试 case 生成, case 类型 --> case --> 预期结果
        std::vector<std::tuple<std::string, std::vector<int>, int, int>> ProductCase();

        // 不同实现方式
        std::vector<Search *> _runners;
    };
} // namespace array_search

#endif //CODE_TO_DAYDAYUP_ARRAY_SEARCH_H

