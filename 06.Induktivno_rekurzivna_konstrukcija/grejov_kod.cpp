#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>

using namespace std;

// kvadratna
string grejov_kod(unsigned n, unsigned k)
{
	if (n == 0)
		return "";

	if (k < (1u << n-1))
		return "0" + grejov_kod(n-1, k);
	else 
		return "1" + grejov_kod(n-1, (1u << n) - 1 - k);
}

// linearna
string grejov_kod_alt(unsigned n, unsigned k)
{
	string res = "";
	while (n > 0) {
		if (k < (1u << n-1))
			res += "0";
		else{ 
			res += "1";
			k = (1u << n) - 1 - k;
		}
		n--;
	}

	return res;
}

int main()
{
	unsigned n, k;
	cin >> n >> k;

	cout << grejov_kod(n, k) << endl;


	return 0;
}
