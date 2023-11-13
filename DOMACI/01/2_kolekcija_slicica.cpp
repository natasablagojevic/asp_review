#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Učitavanje iznosa novca koji Nikola ima
    int iznosNovca;
    std::cin >> iznosNovca;

    // Učitavanje broja kolekcija
    int n;
    std::cin >> n;

    // Učitavanje cena sličica u svakoj kolekciji
    std::vector<int> ceneSlicica(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ceneSlicica[i];
    }

    // Sortiranje cena sličica
    std::sort(ceneSlicica.begin(), ceneSlicica.end());

    // Učitavanje broja upita
    int m;
    std::cin >> m;

    // Rešavanje upita
    for (int i = 0; i < m; i++) {
        // Učitavanje intervala [i, j]
        int a, b;
        std::cin >> a >> b;

        // Pronalaženje broja kolekcija koje zadovoljavaju uslov
        int brojKolekcija = 0;
        for (int k = a; k <= b; k++) {
            if (iznosNovca >= ceneSlicica[k]) {
                iznosNovca -= ceneSlicica[k];
                brojKolekcija++;
            } else {
                break; // Ako Nikola ne može više da kupuje, prekidamo petlju
            }
        }

        // Ispisivanje rezultata
        std::cout << brojKolekcija << std::endl;
    }

    return 0;
}