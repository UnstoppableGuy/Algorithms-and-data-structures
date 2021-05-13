#include <iostream>
#include <algorithm>

template <typename iterator>
bool rebuild(iterator begin, iterator end)
{
    if (begin == end)
        return false;
    iterator i = begin;
    ++i;
    if (i == end)
        return false;
    i = end;
    --i;
    while (true)
    {
        iterator j = i;
        --i;
        if (*i < *j)
        {
            iterator k = end;
            while (!(*i < *--k))
                ;
            iter_swap(i, k);
            reverse(j, end);
            return true;
        }
        if (i == begin)
        {
            reverse(begin, end);
            return false;
        }
    }
}

int main()
{
    std::string X;
    std::cin >> X;    
    if (rebuild(X.begin(), X.end()))
        std::cout << X << std::endl;
    else
        std::cout << "-1" << std::endl;
}