/* 
    Bio je na isptu
    rang_a(x) = broj elemenata iz niza a koji su strogo manji od x
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> niz = a;
    sort(niz.begin(), niz.end());

    for (auto x : a) {
        auto it = lower_bound(niz.begin(), niz.end(), x);

        cout << it - niz.begin() << endl;
    }


	return 0;
}
