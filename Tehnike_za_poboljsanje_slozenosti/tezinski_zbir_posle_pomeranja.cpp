#include<iostream>
#include<vector>

using namespace std;

#define MOD 1234567

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int tezinski_zbir = 0;
	int zbir_svih = 0;

	for (int i = 0; i < n; i++) {
		tezinski_zbir += ((i*a[i]%MOD)%MOD);
		zbir_svih += (a[i] % MOD);
	}

	int max_tezinski_zbir = tezinski_zbir;
	int max_i = 0;

	for (int i = 1; i < n; i++) {
		tezinski_zbir = (tezinski_zbir%MOD - zbir_svih%MOD + n*a[i-1]%MOD)%MOD;

		if (tezinski_zbir > max_tezinski_zbir) {
			max_tezinski_zbir = tezinski_zbir;
			max_i = i;
		}
	}

	cout << max_tezinski_zbir << ' ' << max_i << endl;


	return 0;
}
