//
// Created by xianglong on 2022/10/29.
//

#ifndef CODE_TO_DAYDAYUP_ROTATION_MATRIX_H
#define CODE_TO_DAYDAYUP_ROTATION_MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

namespace rotation_matrix {
    void Test();

    std::vector<std::vector<int>> rotatedMatrixByIteration(int n);

    void print2DArr(std::vector<std::vector<int>> arr);

    class Recursion {
    public:
        std::vector<std::vector<int>> rotatedMatrixByIterationByRecursion(int n);

        void recursion(int i, int j, int right);

    private:
        std::vector<std::vector<int>> _res;
        int _value; // 赋给矩阵的值
        int _n; //矩阵纬度
    };
} // rotation_matrix
#endif //CODE_TO_DAYDAYUP_ROTATION_MATRIX_H
