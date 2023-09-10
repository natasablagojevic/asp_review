#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int tezinski_zbir = 0;
	int zbir_svih = 0;

	for (int i = 0; i < n; i++) {
		zbir_svih += a[i];
		tezinski_zbir += i*a[i];
	}

	int max_tezinski_zbir = tezinski_zbir;
	int max_i = 0;

	for (int i = 1; i < n; i++) {
		tezinski_zbir += n*a[i-1] - zbir_svih;

		if (max_tezinski_zbir < tezinski_zbir) {
			max_tezinski_zbir = tezinski_zbir;
			max_i = i;
		}
	}

	cout << max_tezinski_zbir << ' ' << max_i << endl;


	return 0;
}