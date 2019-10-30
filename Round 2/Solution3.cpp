#include <chrono>
#include <cmath>
#include <iostream>
using namespace std;
const int maxh = 300017;
const int maxn = 15000;
double x[maxn], y[maxn], a, b;
int hash_t[maxh] = {0};
int n, cnt = 0, ans = 0;
int getHash(double a, double b)
{
    long long k = a * 100000 * 7 + b * 999997 * 13;
    if (k < 0)
        k = -k - 1;
    return k % maxh;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            a = (y[i] * x[j] - y[j] * x[i]) / (x[i] * x[j] * (x[i] - x[j]));
            b = (y[i] - a * x[i] * x[i]) / x[i];
            if (a < 0.0)
                hash_t[getHash(a, b)]++;
        }
    for (int i = 0; i < maxh; i++)
        if (hash_t[i] > cnt)
            cnt = hash_t[i];
    cout << (int)(1 + sqrt(1 + 8 * cnt)) / 2 << endl;
}
