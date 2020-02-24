// 简单难度解法
#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        nums[i] = i + 1;
    while (--k)
        std::next_permutation(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i)
        std::cout << nums[i] << ' ';
    return 0;
}