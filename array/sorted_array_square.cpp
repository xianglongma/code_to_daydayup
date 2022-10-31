//
// Created by xianglong on 2022/10/29.
//
#include "sorted_array_square.h"

namespace sorted_array_square {
    // 暴力解法，先平方后排序

    // 左右指针是最优解
    std::vector<int> sortedArraySquare(std::vector<int> &nums) {
        int left = 0;
        int right = nums.size();
        right = right - 1;
        int resultIndex = right;
        // 初始化 nums.size() 个值为 0 的vector<int>
        std::vector<int> result(nums.size(), 0);
        while (left <= right) {
            if (square(nums[left]) < square(nums[right])) {
                result[resultIndex--] = square(nums[right]);
                --right;
            } else {
                result[resultIndex--] = square(nums[left]);
                ++left;
            }
        }
        return result;
    }

    int square(int num) {
        return num * num;
    }
} // sorted_array_square