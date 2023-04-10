#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

// da li je moguc raspored za D >= x
bool ispitaj_rastojanje(int x, int m, vector<int> &a, int n)
{
	m--;
	int poslednja = a[0];

	for (int i = 1; i < n && m > 0; i++)
		if (a[i] - poslednja >= x) {
			m--;
			poslednja = a[i];
		}	

	return m == 0;
}

int main()
{
	int m;
	int n;
	cin >> m >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	/* 
	int d = 1;
	// max * O(n) = O(max * n)
	while (ispitaj_rastojanje(d, m, a, n)) {
		d++;
	} 
	cout << d-1 << endl;
	*/

	// [l, d]
	int l = 1, d = a[n-1];
	int resenje = -1;
	while (l <= d) {
		int s = (l+d)/2;

		if (ispitaj_rastojanje(s, m, a, n)) {
			resenje = s;
			l = s+1;
		} else {
			d = s - 1;
		}
	}

	// zbog toga sto poslednja lokacija nije moguca jer je van opsega
	cout << resenje << endl;

	return 0;
}
