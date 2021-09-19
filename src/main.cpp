#include "sample.h"

#include <iostream>

int main()
{
    int x = 10, y = 20;
    auto ret = sum(x, y);
    std::cout << "x = " << x << " y = " << y << "sum = " << ret << std::endl;
    return 0;
}