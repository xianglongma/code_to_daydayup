# code_to_daydayup

刷题以及刷题笔记

## 2022-10-29

- 有序数组中搜索某个元素

  - 二分查找
  - 双指针查找
- 删除数组中的某个元素

  - 快慢指针
  - 相向双指针
- 序数组的平方

  - 相向双指针
- 长度最小的子数组

  - 快慢指针 & 滑动窗口
- 螺旋矩阵 II

  - 分治思路：:n 维矩阵的螺旋填充可以拆分为 n-1 个螺旋矩形的填充
  - 迭代 & 递归(TODO)
- [904. 水果成篮](https://leetcode.cn/problems/fruit-into-baskets/description/)

  - 双指针 + 滑动窗口

  ```c++
  class Solution {
  public:
      int totalFruit(vector<int>& fruits) {
          map<int, int> hasPicked;
          int slow = 0, fast = 0;
          int result = 0;
          while (fast < fruits.size()) {
              hasPicked[fruits[fast++]] += 1;
              while (hasPicked.size() > 2) {
                  hasPicked[fruits[slow]] -= 1;
                  if (hasPicked[fruits[slow]] == 0) {
                      hasPicked.erase(fruits[slow]);
                  }
                  slow++;
              }
              int len = fast - slow ;
              result = result > len ? result : len;
          }
      return result;
      }
  };
  ```

  - 动态规划
    todo
