#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>
#include<deque>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int t;
	// cin >> t;
	// n--;

	deque<int> q;
	q.push_front(t);

	while (n--) {
		cin >> t;

		if (q.empty() || t < q.front())
			q.push_front(t);
		else 
			q.push_back(t);
	}

	for (int i = 0; i < q.size(); i++)
		cout << q[i] << ' ';
	cout << endl;

	return 0;
}
