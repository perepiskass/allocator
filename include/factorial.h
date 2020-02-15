#pragma once

namespace my_factorial
{
    template<int V>
    struct fact {
        static const int value = V * fact<V-1>::value;
    };

    template<>
    struct fact<0> {
        static const int value = 1;
    };

    constexpr int factorial(int n) 
    {
        switch (n)
        {
        case 0:
            return fact<0>::value;
        case 1:
            return fact<1>::value;
        case 2:
            return fact<2>::value;
        case 3:
            return fact<3>::value;
        case 4:
            return fact<4>::value;
        case 5:
            return fact<5>::value;
        case 6:
            return fact<6>::value;
        case 7:
            return fact<7>::value;
        case 8:
            return fact<8>::value;
        case 9:
            return fact<9>::value;
        case 10:
            return fact<10>::value;
        
        default:
            break;
        }
        return -1; //n == 0 ? 1 : factorial(n - 1) * n;
    }


}