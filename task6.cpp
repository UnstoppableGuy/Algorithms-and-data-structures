#include <iostream>
#include <vector>

int main()
{
    long long N, M;
    std::cin >> N >> M;
    long long arrayofpoints[M][3] = {0};
    long long L = 0, R = 0, V = 0;
    long long **temp = new long long *[N + 1] { {NULL},{NULL} };
    long long nums[N + 1]{-1};
    for (size_t i = 0; i < M; i++)
    {
        std::cin >> L >> R >> V;

        arrayofpoints[i][0] = L - 1;
        arrayofpoints[i][1] = R - 1;
        arrayofpoints[i][2] = V;
    }

    std::qsort(arrayofpoints, M, sizeof(long long) * 3, [](const void *a, const void *b) {
        long long arg1 = *((long long *)a + 2);
        long long arg2 = *((long long *)b + 2);
        if (arg1 < arg2)
            return 1;
        if (arg1 > arg2)
            return -1;
        return 0;
    });
    for (size_t i = 0; i < M; i++)
    {
        L = arrayofpoints[i][0],
        R = arrayofpoints[i][1],
        V = arrayofpoints[i][2];
        long long *a = new long long(L);
        for (size_t j = L; j <= R;)
        {
            if (temp[j] == NULL)
            {
                nums[j] = V;
                temp[j] = a;
                *temp[j] = j + 1;
                j++;
            }
            else
            {
                j = *temp[j];
            }
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        std::cout << nums[i] << " ";
    }
}