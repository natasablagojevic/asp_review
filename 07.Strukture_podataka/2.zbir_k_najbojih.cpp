#include<iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	// priority_queue<int, vector<int>, less> q1;

	priority_queue<int> q;
	while (n--) {
		int x;
		cin >> x;
		q.push(x);
	}

	int sum = 0;
	while (k--) {
		sum += q.top();
		q.pop();
	}

	cout << sum << endl;

	return 0;
}