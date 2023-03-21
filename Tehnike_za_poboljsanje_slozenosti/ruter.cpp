#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)	
		cin >> a[i];

	int levo = 0;
	int desno = 0;
	int duzina = 0;

	for (int i = 0; i < n; i++) {
		desno += a[i];
		duzina += i*a[i];
	}

	int min_duzina = duzina;
	for (int i = 1; i < n; i++) {
		levo += a[i-1];
		desno -= a[i-1];
		duzina += levo - desno;

		if (duzina < min_duzina) {
			min_duzina = duzina;
		}
	}

	cout << min_duzina << endl;


	return 0;
}
