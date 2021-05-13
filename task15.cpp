#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long N;
    std::vector<long long> vec;
    std::cin >> N;
    long long value;
    long long max = 0;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> value;
        vec.push_back(value);
        if (max < value)
        {
            max = value;
        }
    }
    auto iter = vec.cbegin();
    vec.insert(iter, max);
    max = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (vec[i] > vec[i + 1])
        {
            max += vec[i] - vec[i + 1];
        }
    }
    std::cout << max << std::endl;
}
