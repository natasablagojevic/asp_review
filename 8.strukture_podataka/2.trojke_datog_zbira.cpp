#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int brojac = 0;
	set<int> brojevi;

	// b = v[i], c = v[j]
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (brojevi.find(-v[i]-v[j]) != brojevi.end()) 
				brojac++;
		}
		brojevi.insert(v[i]);
	}

	cout << brojac << endl;


	return 0;
}