#include <iostream>
#include <set>

using namespace std;

set<int> s;

void dodaj(int x) 
{
	s.insert(x);
}

void obrisi(int x)
{
	s.erase(x);
} 

int najblizi(int x) 
{
	auto it = s.lower_bound(x);

	if (it == s.end())
		return *(--it);

	if (it == s.begin())
		return *it;

	int a = *it;
	int b = *(--it);

	if (abs(a - x) < abs(b - x)) 
		return a;
	return b;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	while (n--) {
		string operacija;
		cin >> operacija;

		int x;
		cin >> x;

		if (operacija == "dodaj") 
			dodaj(x);
		

		if (operacija == "obrisi") 
			obrisi(x);
		

		if (operacija == "najblizi") 
			cout << najblizi(x) << endl;
	}


	return 0;
}