//
// Created by xianglong on 2022/10/29.
//

#ifndef CODE_TO_DAYDAYUP_REMOVE_ELEM_H
#define CODE_TO_DAYDAYUP_REMOVE_ELEM_H

#include <vector>
#include <iostream>

namespace remove_elem {
    void Test();

    class RemoveElement {
    public:
        virtual int removeElement(std::vector<int> &nums, int val) = 0;

        virtual std::string type() const = 0;
    };

    // 1. 暴力解法 o(n2)
    class ViolenceRemove : public RemoveElement {
        int removeElement(std::vector<int> &nums, int val);

        std::string type() const;
    };

    // 2.快慢指针删除 o(n)
    class TowPointerRemove : public RemoveElement {
        int removeElement(std::vector<int> &nums, int val);

        std::string type() const;
    };

    // 3. 相向双指针 o(n), 元素的相对位置会发生改变, 但是会减少数组元素的赋值次数
    class OppoTowPointerRemove : public RemoveElement {
        int removeElement(std::vector<int> &nums, int val);

        std::string type() const;
    };

    class Runner {
    public:
        // 构造函数
        Runner();

        // 执行测试
        void Runnable();

        ~Runner();

    private:
        // 题目描述
        void _problemDescription();

        void _registerSearch(RemoveElement *re);

        // 测试 case 生成, case 类型 --> case --> 预期结果
        std::vector<std::tuple<std::string, std::vector<int>, int, int>> _productCase();

        // 不同实现方式
        std::vector<RemoveElement *> _res;
    };
} // namespace remove_elem
#endif //CODE_TO_DAYDAYUP_REMOVE_ELEM_H
