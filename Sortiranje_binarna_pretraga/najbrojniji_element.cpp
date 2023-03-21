#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<string> a(n);

	// O(n)
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// O(n*logn)
	sort(a.begin(), a.end());

	int duzina = 1;
	int max_duzina = 1;

	// O(n)
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1]) {
			// resetovanje
			duzina = 1;
		} else {
			duzina++;

			if (duzina > max_duzina)
				max_duzina = duzina;
		}
	}

	cout << max_duzina << endl;


	return 0;
}
