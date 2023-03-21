#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swap(vector<int> &a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void quick_sort(vector<int> &a, int l, int d)
{
	if (l >= d)
		return ;

	int pozicija_pivota = l;
	for (int i = l+1; i <= d; i++) 
		if (a[i] < a[pozicija_pivota]) {
			pozicija_pivota++;
			swap(a, i, pozicija_pivota);
		}

	swap(a, l, pozicija_pivota);
	quick_sort(a, l, pozicija_pivota - 1);
	quick_sort(a, pozicija_pivota + 1, d);

}

int main()
{
	vector<int> a = {2, 8, 7, 1, 3, 5, 6, 4};

	int n = a.size();
	
	quick_sort(a, 0, n-1);

	for (int x : a)
		cout << x << ' ';
	cout << endl;


	return 0;
}
