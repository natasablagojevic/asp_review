#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

struct Takmicar
{
	string ime;
	int bodovi;

	bool operator<(Takmicar &x) {
		if (bodovi > x.bodovi)
			return true;
		if (x.bodovi > bodovi)
			return false;
		
		return ime < x.ime;
	}
};

// true - ako takmicar a traba da bude ispred b
bool sortiraj(Takmicar x1, Takmicar x2)
{
	if (x1.bodovi > x2.bodovi)
		return true;
	else if (x2.bodovi > x1.bodovi)
		return false;
	else 
		return x1.ime == x2.ime;
}

int main()
{
	int n;
	cin >> n;

	vector<Takmicar> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].ime >> a[i].bodovi;

	sort(a.begin(), a.end(), [](Takmicar &x1, Takmicar &x2) {
		return x1.bodovi > x2.bodovi || (x1.bodovi == x2.bodovi && x1.ime < x2.ime);
	});

	for (int i = 0; i < n; i++)
		cout << a[i].ime << ' ' << a[i].bodovi << endl;

	return 0;
}
