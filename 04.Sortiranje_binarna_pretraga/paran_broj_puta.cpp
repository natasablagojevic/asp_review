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

    int broj_parnih = 0;
    int duzina = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1])
            duzina++;
        else {
            if (duzina % 2 == 0)
                broj_parnih++;
            duzina = 1;
        }
    }

    if (duzina % 2 == 0)
        broj_parnih++;

    cout << broj_parnih << endl;


	return 0;
}
