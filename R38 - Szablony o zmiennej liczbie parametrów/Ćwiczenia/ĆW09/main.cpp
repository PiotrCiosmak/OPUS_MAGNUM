#include <iostream>
#include <array>

template<typename T, typename... Args>
void fun(T* pierwszy, Args* ... args)
{
    (*pierwszy)++;

    if constexpr (sizeof...(Args))
    {
        fun(args...);
    }
}

int main()
{
    int n{1};
    double d{50.5};
    char znak{'A'};

    std::cout << "PRZED\n\tn = " << n << ", d = " << d << ", znak = " << znak << std::endl;
    fun(&n, &d, &znak);
    std::cout << "PO\n\tn = " << n << ", d = " << d << ", znak = " << znak << std::endl;
}