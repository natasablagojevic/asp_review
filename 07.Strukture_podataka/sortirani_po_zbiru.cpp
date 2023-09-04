#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>
#include<queue>

using namespace std;

int suma(pair<int, int> p) 
{
	return p.first * p.first + p.second * p.second;
}

struct comparator 
{
	/* 
		Ako hocu minimum u redu sa prioritetom
		znacenje ove funkcije treba da bude sledece
		true ako je x > y
		false u suprotnom;
	 */
	bool operator()(pair<int, int> x, pair<int, int> y) {
		if (suma(x) > suma(y))
			return true;
		
		if (suma(x) < suma(y))
			return false;

		return x.first > y.first;
	}
};

int main()
{
	int n, k;
	cin >> n >> k;

	priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> heap;

	for (int i = 0; i <= n; i++) {
		heap.push({i, i});
	}

	while (k--) {
		pair<int, int> t = heap.top();
		heap.pop();

		if (t.second < n)
			heap.push({t.first, t.second+1});
	}

	pair<int, int> p = heap.top();

	cout << p.first << ' ' << p.second << ' ' << suma(p) << endl;


	return 0;
}
