#include <iostream>
#include <vector>

using namespace std;

int nzd(int a, int b) 
{
	int tmp;
	while (b > 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;

	cout << nzd(a, b) << endl;


	return 0;
}