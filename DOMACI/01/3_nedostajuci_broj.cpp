#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMissingNumber(vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;
    int missing = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int expected = nums[mid] - mid - 1;

        if (expected < k) {
            missing = nums[mid] + k - expected;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return missing;
}

int main() {
    int n, m;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;

        int missingNumber = findMissingNumber(sequence, k);
        cout << missingNumber << endl;
    }

    return 0;
}