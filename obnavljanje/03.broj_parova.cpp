#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int broj_parova_datog_zbira(vector<int> &a, int n, int s)
{
	int brojac = 0;

	int l = 0; 
	int d = n-1;

	while (l < d) {
		if (a[l] + a[d] > s) 
			d--;
		else if (a[l] + a[d] < s) 
			l++; 
		else 
			l++, d--, brojac++;
	} 

	return brojac;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int s;
	cin >> s;

	sort(a.begin(), a.end());

	cout << broj_parova_datog_zbira(a, n, s) << endl;


	return 0;
}