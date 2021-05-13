#include <iostream>
#include <string>
#include <algorithm>

void reverseString(std::string::iterator first, std::string::iterator last)
{
    while ((first != last) && (first != --last))
    {
        std::iter_swap(first++, last);
    }
}

bool check(std::string &string)
{
    for (int i = 0; i < string.length(); i++)
    {
        if (string[i] != string[0])
            return false;
    }
    return true;
}

int main()
{
    std::string S;
    std::cin >> S;
    if (check(S))
    {
        std::cout << "-1" << std::endl;
    }
    else
    {
        std::string copy(S);
        reverseString(copy.begin(), copy.end());
        if (S == copy)
            std::cout << S.size() - 1 << std::endl;
        else
            std::cout << S.size() << std::endl;
    }
}