#include <iostream>
#include <vector>
#include <array>

std::vector<double> small;
std::vector<double> medium;
std::vector<double> large;

template<typename... T>
void fun(T ... args)
{
    std::array<double, sizeof...(args) + 1> all_number{args...};
    for (auto element: all_number)
    {
        if (element < 10)
        {
            small.push_back(element);
        }
        else if (element < 100)
        {
            medium.push_back(element);
        }
        else
        {
            large.push_back(element);
        }
    }
}

int main()
{
    fun(2.2, 3.3, 4.4, 6665.5, 4.5, 34.6, 34.7, 35.8, 34.9, 324234.3, 4324234.4);

    std::cout << "---SMALL---" << std::endl;
    for (const auto& element: small)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "---MEDIUM---" << std::endl;
    for (const auto& element: medium)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "---LARGE---" << std::endl;
    for (const auto& element: large)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;
}