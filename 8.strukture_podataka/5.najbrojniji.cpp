#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	map<string, int> br_glasova;

	while (n--) {
		string ime;
		cin >> ime;

		br_glasova[ime]++;		
	}

	int max_glasova = 0;
	for (auto p : br_glasova) {
		if (p.second > max_glasova)
			max_glasova = p.second;
	}
	
	cout << max_glasova << endl;

	return 0;
}