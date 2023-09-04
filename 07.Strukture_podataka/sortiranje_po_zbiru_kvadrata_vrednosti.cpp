#include<iostream>
#include <queue>

using namespace std;

int suma(pair<int, int> p)
{
	return p.first*p.first + p.second*p.second;
}

/*
	ako hocu minimu u priority_queue
	znacenje ove funkcije treba da bude:
	TRUE ako je x1 < x2 (x2 treba da se nadje na vrhu a ne x1) 
	FALSE inace 
*/
struct comparator
{
	bool operator()(pair<int, int> x1, pair<int, int> x2) {
		if (suma(x2) < suma(x1))
			return true;
		if (suma(x2) > suma(x1))
			return false;
		return x2.first < x1.first;
	}
};

int main()
{
	 // alternativa: sortiranje + poslednjih k elemenata

	int n, k;
	cin >> n >> k;

	priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> heap;

	for (int i = 0; i <= n; i++) {
		heap.push({i, i});
	}

	while (k--) {
		auto t = heap.top();
		heap.pop();

		if (t.second < n) 
			heap.push({t.first, t.second+1});
	}

	auto t = heap.top();
	cout << t.first << ' ' << t.second << ' ' << suma(t) << endl;



	return 0;
}