#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
    int n, s;
    cin >> s >> n;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
        cin >> niz[i];

    sort(niz.begin(), niz.end());

    int broj_parova = 0;
    for (int i = 0; i < n; i++) {
        if (binary_search(niz.begin(), niz.begin() + i, s-niz[i])) // O(logn)
            broj_parova++;
    }

    cout << broj_parova << endl;


	return 0;
}
