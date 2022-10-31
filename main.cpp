#include <iostream>
#include "array_search.h"
int main() {
    try {
        array_search::Runner runner;
        runner.Runnable();
    }catch (std::out_of_range e) {
        std::cout << "单测执行失败" << std::endl;
        std::cout << e.what()<< "下标访问越界" << std::endl;
    }
    return 0;
}
