#include <iostream>
#include <vector>

long long counter = 0;

long long *mergeSort(long long *up, long long *down, long long begin, long long end)
{
    if (begin == end)
    {
        down[begin] = up[begin];
        return down;
    }
    long Average = (begin + end) / 2;
    long long *Left = mergeSort(up, down, begin, Average);
    long long *Right = mergeSort(up, down, Average + 1, end);
    long long *target = Left == up ? down : up;
    long long l = begin, r = Average + 1;
    for (int i = begin; i <= end; i++)
    {
        if (l <= Average && r <= end)
        {
            if (Left[l] < Right[r])
            {
                target[i] = Left[l];
                l++;
            }
            else
            {
                target[i] = Right[r];
                r++;
                counter += Average - begin + 1 - (l - begin);
            }
        }
        else if (l <= Average)
        {
            target[i] = Left[l];
            l++;
        }
        else
        {
            target[i] = Right[r];
            r++;
        }
    }
    return target;
}


int main()
{
    long long N;
    std::cin >> N;
    long long *array = new long long[N]{0};
    long long *temp = new long long[N]{0};
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> array[i];
    }
    mergeSort(array, temp, 0, N - 1);
    std::cout << counter << std::endl;
}

