#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int min_skok(const std::vector<int> nums)
{
    int n = nums.size();
    std::vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; i--) {
        int minSkok = INT_MAX;

        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < n && dp[i+j] != -1) {
                minSkok = std::min(minSkok, dp[i + j] + 1);
            }
        }

        dp[i] = (minSkok == INT_MAX) ? -1 : minSkok;
    }

    return dp[0];
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    std::cout << min_skok(nums) << std::endl;

    return 0;
}