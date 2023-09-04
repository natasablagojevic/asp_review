#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>
#include<queue>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	priority_queue<int, vector<int>, less<int>> najveci_k;

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		najveci_k.push(x);
	}

	for (int i = k; i < n; i++) {
		int x;
		cin >> x;

		if (x > najveci_k.top()) {
			najveci_k.pop();
			najveci_k.push(x);
		}
	}

	int zbir = 0;
	while (!najveci_k.empty()) {
		zbir += najveci_k.top();
		najveci_k.pop();
	}

	cout << zbir << endl;

	return 0;
}
