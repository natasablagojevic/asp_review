#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int saberi(vector<int> &a, int x, int y)
{
	int n = a.size();
	int sum = 0;


	// O(y-x) -> u najgorem slucaju O(n)
	for (int i = x; i <= y; i++)
		sum += a[i];

	return sum;
}

int main()
{
	int n;
	cin >> n;

	// O(n)
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> pr(n+1, 0);
	// for (int i = 1; i <= n; i++)
		// pr[i] = pr[i-1] + a[i];

	partial_sum(a.begin(), a.end(), pr.begin() + 1);

	int m;
	cin >> m;

	int x, y;

	// O(m + n)
	while (m--) {
		cin >> x >> y;

		cout << pr[y+1] - pr[x] << endl;
	}
 

	return 0;
}
