#include <climits>
#include <fstream>
#include <random>
#include <string>
#include <utility>

using namespace std::literals;

long long frac(long long i)
{
    if (i == 1)
        return 1;
    long long tmp = frac(i - 1);
    if (i * tmp > INT_MAX)
        return INT_MAX;
    return i * tmp;
}

int main(int argc, char const *argv[])
{
    std::pair<int, long long> data[][5] = {
        {{3, 4}, {4, 20}, {5, 120}, {9, 181440}, {12, 179001600}},
        {{2500, 131487102}, {5000, 738214612}, {12000, 123124124}, {25000, 175611234}, {25000, 97643356}}};
    std::default_random_engine re{std::random_device{}()};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 5; ++j)
        {
            char sym = (i == 0 ? 'E' : 'H');
            std::ofstream fout{"Round 3/in/"s + sym + std::to_string(j) + ".txt"};
            data[i][j].second = std::uniform_int_distribution<>{1, static_cast<int>(frac(data[i][j].first))}(re);
            fout << data[i][j].first << ' ' << data[i][j].second;
        }
    return 0;
}
