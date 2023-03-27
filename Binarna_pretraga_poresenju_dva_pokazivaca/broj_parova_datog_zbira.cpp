#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>

using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int broj_parova = 0;
    // int j = n-1;
    // for (int i = 0; i < j; i++) {
    //     while (i < j && a[i] + a[j] < s) 
    //         j--;

    //     if (a[i] + a[j] == s)
    //         broj_parova++;
    // }

    int l = 0, d = n-1;
    while (l < d) {
        if (a[l] + a[d] == s) {
            broj_parova++;
            l++;
            d--;
        } else if (a[l] + a[d] > s) 
            d--;
        else 
            l++;
    }

    cout << broj_parova << endl;
	return 0;
}
