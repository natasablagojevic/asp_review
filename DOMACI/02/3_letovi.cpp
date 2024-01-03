#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countRealisticPairs(vector<int>& delays) {
    int n = delays.size();
    sort(delays.begin(), delays.end()); // Sortiranje niza

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int left = i + 1, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (delays[mid] - delays[i] <= mid - i) {
                count += mid - i;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> delays(n);
    for (int i = 0; i < n; ++i) {
        cin >> delays[i];
    }

    long long result = countRealisticPairs(delays);
    cout << result << endl;

    return 0;
}
