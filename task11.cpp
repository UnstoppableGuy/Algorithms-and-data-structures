#include <iostream>
#include <algorithm>
#include <vector>

long long modul = 1e7 + 7;
long long result = 0;

void dfs(std::pair<long long, long long> pair, std::vector<std::pair<long long, long long>> *g, long long *sum, long long *temp)
{
    temp[pair.first] = 1;
    for (size_t i = 0; i < g[pair.first].size(); i++)
    {
        std::pair<long long, long long> node = g[pair.first][i];
        if (node.first != pair.second)
        {
            dfs(std::make_pair(node.first, pair.first), g, sum, temp);
            temp[pair.first] = (temp[pair.first] + temp[node.first]) % modul;
            sum[pair.first] = (sum[pair.first] + (sum[node.first] + temp[node.first] * node.second) % modul) % modul;
        }
    }
    for (size_t i = 0; i < g[pair.first].size(); i++)
    {
        std::pair<long long, long long> node = g[pair.first][i];
        if (node.first != pair.second)
        {
            result += node.second * (temp[node.first]) % modul * (temp[pair.first] - temp[node.first]) % modul;
            result %= modul;
            result += sum[node.first] * (temp[pair.first] - temp[node.first]) % modul;
            result %= modul;
        }
    }
}

int main()
{
    long long N;
    std::cin >> N;
    std::vector<std::pair<long long, long long>> g[N];
    long long A, B, C;
    long long *temp = new long long[N];
    long long *temp2 = new long long[N];
    for (size_t i = 0; i < N - 1; i++)
    {
        std::cin >> A >> B >> C;
        g[A - 1].push_back(std::make_pair(B - 1, C));
        g[B - 1].push_back(std::make_pair(A - 1, C));
    }
    dfs(std::make_pair(0, -1), g, temp, temp2);
    result = (result * 2) % modul;
    std::cout << result << std::endl;
    return 0;
}
