#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<limits>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	auto it = unique(a.begin(), a.end());
	a.erase(it, a.end());

	int pocetak = 0;
	int duzina = 1;

	int max_pocetak = pocetak;
	int max_duzina = duzina;

	for (int i = 1; i < n; i++) {
		if (a[i] - a[i-1] == 1) {
			duzina++;

			if (duzina > max_duzina) {
				max_duzina = duzina;
				max_pocetak = pocetak;
			} else {
				pocetak = i;
				duzina = 1;
			}
		}
	}

	int start = max_pocetak;
	int end = max_pocetak + max_duzina;
	for (int i = start; i < end; i++)
		cout << a[i] << ' ';
	cout << endl;




	return 0;
}