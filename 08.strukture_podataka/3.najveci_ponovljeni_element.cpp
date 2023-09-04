#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	cin >> n; 

	set<int> brojevi;
	int najveci = 0;

	while (n--) {
		int x;
		cin >> x;

		if (brojevi.find(x) != brojevi.end() && x > najveci) {
			najveci = x;
		}

		brojevi.insert(x);
	}	

	if (najveci > 0) 
		cout << najveci << endl;
	else 
		cout << "nema" << endl;


	return 0;
}