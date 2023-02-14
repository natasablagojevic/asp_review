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

    int sum = 0;
    int max = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (sum > max) {
            max = sum;
        }
    }

    cout << max << endl;


    return 0;
}