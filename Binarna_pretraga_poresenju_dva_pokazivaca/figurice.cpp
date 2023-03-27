#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int64_t t;
	cin >> t;

	sort(a.begin(), a.end());

	int j = 0;
	int maxK = 0;
	int64_t razlika = 0;
	for (int64_t i = 0; i < n; i++) {
		while ((i-j+1)* (a[i] - a[j]) > t)
			j++;

		// trazim min razliku
		if (i-j+1 > maxK || (i-j+1 == maxK && razlika > (i-j+1)*(a[i] - a[j]))) {
			maxK = i-j+1;
			razlika = (i-j+1)*(a[i] - a[j]);
		}
	}

	cout << maxK  << ' ' << razlika << endl;


	return 0;
}
