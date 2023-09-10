#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> poznaje(n, vector<int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> poznaje[i][j];

	int mozda = 0;
	for (int i = 1; i < n; i++)
		if (poznaje[mozda][i])
			mozda = i;

	bool zvezda = true;
	for (int i = 0; i < n; i++){
		if (i != mozda && !poznaje[i][mozda])
			zvezda = false;
		if (i != mozda && !poznaje[mozda][i])
			zvezda = false;
	}

	if (zvezda)
		cout << mozda << endl;
	else 
		cout << "nema zvezde" << endl;

	return 0;
}
