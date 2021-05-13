#include <iostream>
#include <vector>

int main()
{
    int N;
    bool is1021 = false;
    bool is1031 = false;
    bool is1033 = false;
    bool is1 = false;
    bool ismax = false;
    std::cin >> N;
    long value;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> value;
        if (value == 1)
        {
            is1 = true;
        }
        else if (value == 1021)
        {
            is1021 = true;
        }
        else if (value == 1031)
        {
            is1031 = true;
        }
        else if (value == 1033)
        {
            is1033 = true;
        }
        else if (value == (1021 * 1031))
        {
            is1021 = true;
            is1031 = true;
        }
        else if (value == (1021 * 1033))
        {
            is1021 = true;
            is1033 = true;
        }
        else if (value == (1033 * 1031))
        {
            is1033 = true;
            is1031 = true;
        }
        else if (value == (1021 * 1031 * 1033))
        {
            ismax = true;
        }
    }
    if ((is1021 == true && is1031 == true && is1033 == true) || (ismax == true))
    {
        std::cout << "YES ";
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}