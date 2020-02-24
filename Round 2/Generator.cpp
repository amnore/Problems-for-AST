#include <cmath>
#include <fstream>
#include <iomanip>
#include <random>
#include <string>
using namespace std::literals;
int main()
{
    std::default_random_engine re{std::random_device{}()};
    int arr[3][10] = {{5, 10, 20, 80, 320, 640, 1000, 1000, 1000, 1000},
                      {1200, 1400, 1600, 1800, 1900, 2000, 2000, 2000, 2000, 2000},
                      {3000, 5000, 8000, 11000, 14000, 15000, 15000, 15000, 15000, 15000}};
    for (int i = 0; i < 3; ++i)
    {
        char sym;
        switch (i)
        {
        case 0:
            sym = 'E';
            break;
        case 1:
            sym = 'H';
            break;
        case 2:
            sym = 'I';
            break;
        }
        for (int j = 0; j < 10; ++j)
        {
            std::uniform_real_distribution<> genline{0.0, sqrt(arr[i][j])};
            std::ofstream fout{"Round 2/Test/in/"s + sym + std::to_string(j) + ".txt"};
            std::ofstream logout{"Round 2/Log/"s + sym + std::to_string(j) + ".txt"};
            std::ofstream ansout{"Round 2/Test/out/"s + sym + std::to_string(j) + ".txt"};
            fout << arr[i][j] << '\n';
            int current = 0, max_n = 0;
            while (current < arr[i][j])
            {
                int n =
                    std::uniform_int_distribution<>{1, std::min(arr[i][j] - current, std::max(arr[i][j] / 5, 100))}(re);
                current += n;
                max_n = std::max(max_n, n);
                double a = -genline(re), b = genline(re);
                double div = -b / a, idiv = -a / b;
                double delta = div / (n + 2);
                logout << "R" << current << ": n = " << n << " a = " << a << " b = " << b << '\n';
                double tmp = 0;
                while (n--)
                {
                    tmp += delta;
                    fout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << tmp << ' '
                         << a * tmp * tmp + b * tmp << '\n';
                }
            }
            ansout << max_n << '\n';
        }
    }
}