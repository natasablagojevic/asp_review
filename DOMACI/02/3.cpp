#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> delays(n);
    for (int i = 0; i < n; ++i) {
        cin >> delays[i];
    }

    map<int, int> count;
    long long pairs = 0;
    for (int i = 0; i < n; ++i) {
        pairs += count[delays[i] - i - 1];
        count[delays[i] - i - 1]++;
    }

    cout << pairs << endl;

    return 0;
}
