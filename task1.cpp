#include <iostream>
#include <vector>

void dfs(int v, bool *used, std::vector<std::vector<int>> &g)
{
    used[v] = true;
    for (std::vector<int>::iterator i = g[v].begin(); i != g[v].end(); ++i)
        if (!used[*i])
            dfs(*i, used, g);
}

int connectedness(int N, bool *used, std::vector<std::vector<int>> g)
{
    int counter = 0;
    for (size_t i = 0; i < N; ++i)
        used[i] = false;
    for (size_t i = 0; i < N; ++i)
        if (!used[i])
        {
            dfs(i, used, g);
            counter++;
        }
    return counter;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> g(N);
    bool *used = new bool[N];
    int U, V;
    for (size_t i = 0; i < M; i++)
    {
        std::cin >> U >> V;
        g[U - 1].push_back(V - 1);
        g[V - 1].push_back(U - 1);
    }
    std::cout << (connectedness(N, used, g) - 1) << std::endl;
    return 0;
}