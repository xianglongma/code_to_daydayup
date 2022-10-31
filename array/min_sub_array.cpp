//
// Created by xianglong on 2022/10/29.
//
#include "min_sub_array.h"

namespace min_sub_array {
    // 暴力方法： 双重 for 循环

    // 双指针 滑动窗口 o(n) 最坏情况 o(2n)
    int minSubArray(int s, std::vector<int> &nums) {
        int fast = 0, slow = 0;
        int sum = 0;
        int result = nums.size();
        while (fast < nums.size()) {
            sum += nums[fast];
            while (sum >= s) {
                int len = fast - slow + 1;
                result = result < len ? result : len;
                sum -= nums[slow++];
            }
        }
        return result == nums.size() ? 0 : result;
    }
} // min_sub_array

// 1 2 3
// 8 9 4
// 7 6 5