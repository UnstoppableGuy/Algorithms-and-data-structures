#include <iostream>

void invers(std::string &str, bool *letters)
{
    bool flag = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (letters[i])
            flag = !flag;
        if (flag)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= ' ';
                continue;
            }
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += ' ';
                continue;
            }
        }
    }
}

int main()
{
    std::string S;
    std::cin >> S;
    int Q, L, R;
    bool *caseofletters = new bool[S.length() + 1]{};
    std::cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        std::cin >> L >> R;
        if (L > R)
            std::swap(L, R);
        caseofletters[L - 1] = !caseofletters[L - 1];
        caseofletters[R] = !caseofletters[R];
    }
    invers(S, caseofletters);
    std::cout << S << std::endl;
}