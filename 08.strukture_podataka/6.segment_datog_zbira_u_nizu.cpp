#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int z, n;
	cin >> z >> n; 

	map<int, int> broj_prefiksa;
	// broj_prefiksa[3] = 2   ; 3 se 2 puta pojavila

	broj_prefiksa[0] = 1;
	int suma = 0;
	int broj_segmenata = 0;

	while (n--) {
		int x;
		cin >> x;

		suma += x;

		broj_segmenata += broj_prefiksa[suma - z];
		broj_prefiksa[suma]++;
	}

	cout << broj_segmenata << endl;


	return 0;
}