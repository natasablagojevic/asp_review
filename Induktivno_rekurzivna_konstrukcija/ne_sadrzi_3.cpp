#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>

using namespace std;

string f(string n)
{
	int br_cifara = n.length();

	int c = n[0] - '0';
	string devetke;
	devetke.resize(br_cifara -1, '9');
	string ostatak = n.substr(1);

	if (c < 3)
		return c*f(devetke) + f(ostatak);
	if (c == 3)
		return c * f(devetke);
	if (c > 3)
		return (c-1) * f(devetke) + fostatak;
}

// izdvajanje cifri sa zadnje strane
string f_alt(int n)
{
	int broj_bez_3 = 1;
	int devetke = 1;

	while (n > 0) {
		int c = n % 10;

		if (c < 3)
			broj_bez_3 = c*devetke + broj_bez_3;
		if (c == 3)
			broj_bez_3 = c*devetke;
		if (c > 3)
			broj_bez_3 = (c-1) * devetke + broj_bez_3;

		devetke *= 9;
		n /= 10;
	}
}

int main()
{
	string n;
	cin >> n;

	cout << f(n) << endl;

	return 0;
}
