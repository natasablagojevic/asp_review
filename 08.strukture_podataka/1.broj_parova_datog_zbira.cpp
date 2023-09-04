#include <iostream>
#include <set>

using namespace std;

int main()
{
	int s;
	cin >> s; 

	int n;
	cin >> n;

	set<int> brojevi;
	int brParova = 0;

	while (n--) {
		int x;
		cin >> x;

		if (brojevi.find(s-x) != brojevi.end())
			brParova++;

		brojevi.insert(x);
	}

	cout << brParova << endl;

	
	return 0;
}