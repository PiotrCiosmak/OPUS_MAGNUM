#include <iostream>

void fun(int a, double b);

int main()
{
    fun(1, 2.2);
}

void fun(int a, double b)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

}