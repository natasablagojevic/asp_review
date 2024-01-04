#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> position(n);
    vector<int> power(n);
    vector<char> direction(n);

    for (int i = 0; i < n; ++i) {
        cin >> position[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> power[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> direction[i];
    }

    map<int, int> survivors;

    for (int i = 0; i < n; ++i) {
        if (survivors.find(position[i]) != survivors.end()) {
            int idx = survivors[position[i]];

            if (power[i] > power[idx]) {
                survivors[position[i]] = i;
            }

            power[idx]--;
        } else {
            survivors[position[i]] = i;
        }

        if (direction[i] == 'D') {
            position[i]++;
        } else {
            position[i]--;
        }
    }

    vector<int> result;

    for (auto const& pair : survivors) {
        result.push_back(power[pair.second]);
    }

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
