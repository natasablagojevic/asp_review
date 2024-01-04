#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int min_skok(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0); // dp čuva minimalan broj skokova za svako polje

    // Iteracija unazad
    for (int i = n - 2; i >= 0; --i) {
        int minJumps = INT_MAX;

        // Provera dužine skoka sa trenutnog polja do kraja
        for (int j = 1; j <= nums[i]; ++j) {
            if (i + j < n && dp[i + j] != -1) {
                minJumps = min(minJumps, dp[i + j] + 1);
            }
        }

        // Ako je minJumps ostao INT_MAX, znači da nije moguće stići do kraja
        dp[i] = (minJumps == INT_MAX) ? -1 : minJumps;
    }

    return dp[0]; // Vraćamo rezultat za početno polje
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = minJump(nums);
    cout << result << endl;

    return 0;
}
