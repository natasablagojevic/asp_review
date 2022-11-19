#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int max = INT_MIN;
    int duzina = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            duzina++;
        } else {

            if (duzina > max) {
                max = duzina;
            }

            duzina = 0;
        }
    }

    if (duzina > max)
        max = duzina;

    cout << max << endl;


    return 0;
}