#include <iostream>

int main()
{
    std::string X;
    std::cin >> X;
    if (X[X.length() - 1] == 48)
    {
        std::cout << "NO" << std::endl;
    }
    else
    {
        std::cout << X[X.length() - 1] << std::endl;
    }
}