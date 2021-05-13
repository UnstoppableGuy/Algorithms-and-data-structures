#include <iostream>
#include <vector>
#include <algorithm>
long long value = 0;/*
template <class iterator, class T>
constexpr iterator find(iterator first, iterator last, const T &value)
{
    for (; first != last; ++first)
    {
        if (*first == value)
        {
            return first;
        }
    }
    return last;
}
*/
void dfs(long long v, bool *used, std::vector<long long> *g)
{
    used[v] = true;
    long long to;
    while (!g[v].empty())
    {
        to = g[v].back();
        g[v].pop_back();
        g[to].erase(find(g[to].begin(), g[to].end(), v));
        if (!used[to])
            dfs(to, used, g);
        else
            ++value;
    }
}

int main()
{
    long long N, M;
    std::cin >> N >> M;
    long long val2 = 0;
    std::vector<long long> g[N];
    bool used[N]{false};
    long long A, B;
    for (size_t i = 0; i < M; i++)
    {
        std::cin >> A >> B;
        if (find(g[A - 1].begin(), g[A - 1].end(), B - 1) != g[A - 1].end())
            ++val2;
        g[A - 1].push_back(B - 1);
        g[B - 1].push_back(A - 1);
    }
    dfs(0, used, g);
    for (size_t i = 0; i < N; ++i)
        if (!used[i])
        {
            value = -1;
            val2 = 0;
            break;
        }
    std::cout << value + val2 << std::endl;
}