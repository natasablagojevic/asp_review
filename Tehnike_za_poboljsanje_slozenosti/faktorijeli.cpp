// Inkrementalnost

#include<iostream>

using namespace std;

uint64_t faktorijel(int n)
{
	uint64_t p = 1;
	for (int i = 1; i <= n; i++)
		p *= i;

	return p;
}

int main()
{
	int n;
	cin >> n;

	uint64_t f = 1;

	for (int i = 1; i <= n; i++) {
		f *= i;

		cout << f << endl;
	}


	return 0;
}
