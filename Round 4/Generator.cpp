#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <utility>
using namespace std::literals;
int main()
{
    std::pair<int, int> data_range[10] = {
        {4, 50},      {8, 100},       {16, 200},        {32, 1600},         {64, 3200},
        {128, 12800}, {256, 1024000}, {512, 536870912}, {1000, 1073741824}, {1000, 2147483647}};
    std::default_random_engine re{static_cast<std::default_random_engine::result_type>(time(nullptr))};
    system("cd Round\\ 4 && g++ Solution.c -Ofast");
    for (int i = 0; i < 10; ++i)
    {
        std::uniform_int_distribution<> rand{1, data_range[i].second};
        std::ofstream fin{"Round 4/Test/in/" + std::to_string(i) + ".txt"};
        fin << data_range[i].first << '\n';
        for (int k = 0; k < data_range[i].first; ++k)
            fin << rand(re) << '\n';
        fin.close();
        auto cmd_str = "cd Round\\ 4 && (./a.out < Test/in/" + std::to_string(i) + ".txt) > Test/out/" +
                       std::to_string(i) + ".txt";
        system(cmd_str.c_str());
    }
    system("cd Round\\ 4 && rm a.out");
    return 0;
}
