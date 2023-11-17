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
    int ukupanBrojKolekcija = 0;
    for (int i = 0; i < m; i++) {
        // Učitavanje intervala [i, j]
        int a, b;
        std::cin >> a >> b;

        // Pronalaženje broja kolekcija koje zadovoljavaju uslov
        int brojKolekcija = 0;
        for (int k = 0; k < n; k++) {
            if (ceneSlicica[k] >= a && ceneSlicica[k] <= b && iznosNovca >= ceneSlicica[k]) {
                iznosNovca -= ceneSlicica[k];
                brojKolekcija++;
            }
        }

        // Dodavanje broja kolekcija za trenutni upit na ukupan broj kolekcija
        ukupanBrojKolekcija += brojKolekcija;

        // Ispisivanje rezultata
        std::cout << ukupanBrojKolekcija << std::endl;
    }

    return 0;
}