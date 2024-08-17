#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Warrior {
    int position;
    int strength;
    char direction;
};

int main() {
    int n;
    cin >> n;

    vector<Warrior> warriors(n);
    for (int i = 0; i < n; ++i) {
        cin >> warriors[i].position >> warriors[i].strength >> warriors[i].direction;
    }

    sort(warriors.begin(), warriors.end(), [](const Warrior& w1, const Warrior& w2) {
        return w1.position < w2.position;
    });

    vector<Warrior> survivors;
    for (const auto& warrior : warriors) {
        if (survivors.empty()) {
            survivors.push_back(warrior);
        } else {
            Warrior& prev = survivors.back();
            if (prev.position == warrior.position) {
                if (prev.strength < warrior.strength) {
                    survivors.pop_back();
                    survivors.push_back(warrior);
                }
            } else {
                if (prev.strength > warrior.strength) {
                    survivors.push_back(warrior);
                }
            }
        }
    }

    for (const auto& survivor : survivors) {
        cout << survivor.strength << " ";
    }
    cout << endl;

    return 0;
}
