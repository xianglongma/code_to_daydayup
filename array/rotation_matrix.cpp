//
// Created by xianglong on 2022/10/29.
//

#include "rotation_matrix.h"

namespace rotation_matrix {
    void Test() {
        print2DArr(rotatedMatrixByIteration(5));
    }

    // n --> n * n 的螺旋矩阵

    // 迭代法
    std::vector<std::vector<int>> rotatedMatrixByIteration(int n) {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0)); // 使用vector定义一个二维数组
        // 可以采用分治算法 可以拆分为最小子问题:n 维矩阵的螺旋填充可以拆分为 n-1 个螺旋矩形的填充
        int x = 0, y = 0; // 螺旋矩形的左上角坐标
        int value = 1; // 每次填充的数值
        int loop = n;
        while (--loop) {
            int i = x, j = y;
            // 上边
            while (j < loop) {
                res[i][j++] = value++;
            }
            // 右边
            while (i < loop) {
                res[i++][j] = value++;
            }
            // 下边
            while (j > x) {
                res[i][j--] = value++;
            }
            // 左边
            while (i > y) {
                res[i--][j] = value++;
            }
            x++;
            y++;
        }
        // 给最中间的赋值
        if (n % 2) {
            res[n / 2][n / 2] = value;
        }
        return res;
    }

    void Recursion::recursion(int i, int j, int right) {
        if (i < 0 || i >= this->_n || j < 0 || j >= this->_n) return;
        this->_res[i][j] = this->_value++;
    }

    std::vector<std::vector<int>> Recursion::rotatedMatrixByIterationByRecursion(int n) {
        this->_n = n;
        std::vector<std::vector<int>>(n, std::vector<int>(n, 0)).swap(this->_res);
        return this->_res;
    }


    void print2DArr(std::vector<std::vector<int>> arr) {
        for (auto vout: arr) {
            for (auto vin: vout) {
                std::cout << vin << "\t";
            }
            std::cout << std::endl;
        }
    }
} // rotation_matrix