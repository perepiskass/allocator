#pragma once

namespace my_factorial
{
    constexpr int factorial(int n) 
    {
        return n == 0 ? 1 : factorial(n - 1) * n;
    }
}