#include <iostream>
#include <vector>

const long long MAX = 1000000000000;

std::vector<long long> dijkstra(long long N, long long A, std::vector<std::pair<long long, long long>> *g)
{
    std::vector<long long> distance(N, MAX), parents(N);
    distance[A - 1] = 0;
    std::vector<bool> used(N);
    for (size_t i = 0; i < N; ++i)
    {
        long long v = -1;
        for (size_t j = 0; j < N; ++j)
            if (!used[j] && (v == -1 || distance[j] < distance[v]))
                v = j;
        if (distance[v] == MAX)
            break;
        used[v] = true;
        for (size_t j = 0; j < g[v].size(); ++j)
        {
            long long to = g[v][j].first;
            long long length = g[v][j].second;
            if (distance[v] + length < distance[to])
            {
                distance[to] = distance[v] + length;
                parents[to] = v;
            }
        }
    }
    return distance;
}

int main()
{
    long long N, M;
    std::cin >> N >> M;
    std::vector<std::pair<long long, long long>> g[N];
    long long A, B, C;
    for (size_t i = 0; i < M; i++)
    {
        std::cin >> A >> B >> C;
        g[A - 1].push_back(std::make_pair(B - 1, C));
        g[B - 1].push_back(std::make_pair(A - 1, C));
    }
    std::cin >> A >> B;
    std::vector<long long> distance(N, MAX), parents(N);
    distance[A - 1] = 0;
    std::vector<bool> used(N);
    for (size_t i = 0; i < N; ++i)
    {
        long long v = -1;
        for (size_t j = 0; j < N; ++j)
            if (!used[j] && (v == -1 || distance[j] < distance[v]))
                v = j;
        if (distance[v] == MAX)
            break;
        used[v] = true;
        for (size_t j = 0; j < g[v].size(); ++j)
        {
            long long to = g[v][j].first;
            long long length = g[v][j].second;
            if (distance[v] + length < distance[to])
            {
                distance[to] = distance[v] + length;
                parents[to] = v;
            }
        }
    }
    std::cout << distance[B - 1] << std::endl;
    //std::cout << dijkstra(N, A, g)[B - 1] << std::endl;
}