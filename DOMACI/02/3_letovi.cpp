#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> position(n), power(n);
    vector<char> direction(n);

    // Učitavanje pozicija, snage i smerova svakog ratnika
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
        if (direction[i] == 'D') {
            // Ako ratnik ide u desno (D), dodajemo ga u mapu preživelih
            survivors[position[i]] = power[i];
        } else {
            // Ako ratnik ide ulevo (L), proveravamo da li postoji borac na toj poziciji
            auto it = survivors.lower_bound(position[i]);
            if (it != survivors.begin()) {
                --it;
                if (it->second <= power[i]) {
                    // Ako je pronađen ratnik sa manjom snagom, uklanjamo ga
                    survivors.erase(it);
                } else {
                    // Ako je pronađen ratnik sa većom snagom, smanjujemo njegovu snagu za 1
                    it->second -= 1;
                }
            }
        }
    }

    // Ispis preživelih ratnika
    for (const auto& survivor : survivors) {
        cout << survivor.second << " ";
    }
    cout << endl;

    return 0;
}
