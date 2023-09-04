#include <iostream>
#include <map>

using namespace std;

map<int, int> m;
int uvecanje = 0;

int vrednost(int x) 
{
	return m[x] + uvecanje;
}

void uvecaj(int x, int y)
{
	m[x] += y;
}

void obrisi(int x) 
{
	m.erase(x);
}

void dodaj(int x, int y)
{
	m[x] = y - uvecanje;
}

void uvecaj_sve(int y)
{
	uvecanje += y;
}

int main(int argc, char const *argv[])
{
	


	return 0;
}