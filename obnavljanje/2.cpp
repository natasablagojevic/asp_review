#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> ps1(n+1);
	partial_sum(a.begin(), a.end(), ps1.begin() + 1);

	for (int x : ps1)
		cout << x << ' ';
	cout << endl;

	vector<int> ps2(n+1);
	for (int i = 0; i < n; i++)
		ps2[i+1] = ps2[i] + a[i];

	cout << "------------------" << endl;

	for (int x : ps2)
		cout << x << ' ';
	cout << endl;

	cout << "Segment oblika [x,y]: ";
	int x, y;
	cin >> x >> y;

	cout << (ps1[y+1] - ps1[x]) << endl;





	return 0;
}