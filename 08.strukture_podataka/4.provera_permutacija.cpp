#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n;

	multiset<int> a;
	while (n--) {
		int x;
		cin >> x;
		a.insert(x);
	}

	cin >> m;

	multiset<int> b;
	while (m--) {
		int x;
		cin >> x;
		b.insert(x);
	}

	cout << (a == b ? "DA" : "NE") << endl;

	return 0;
}