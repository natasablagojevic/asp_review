#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> ps(n+1);
	partial_sum(a.begin(), a.end(), ps.begin() + 1);

	for (int x : ps)
		cout << x << ' ';
	cout << endl;

	cout << "Unesite segmenat za koji racunamo zbir: " ;
	int x, y;
	cin >> x >> y;

	cout << (ps[y+1] - ps[x]) << endl;



	return 0;
}