#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int min_razlika(int k, int n, vector<int64_t> &a, int64_t t)
{
    int min_r = numeric_limits<int>::max();

    for (int i = 0; i+k-1 < n; i++) {
        min_r = min(min_r, k*(a[i+k-1] - a[i]));
        // if (k*(a[i+k-1] - a[i]) <= t) 
        //     return true;
    }

    return min_r;
}

int main()
{
    int n;
    cin >> n;

    vector<int64_t> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int64_t t;
    cin >> t;
    
    int resenje = -1, razlika;
    int l = 0, d = n;
    while (l <= d) {
        int s = (l+d)/2;
        int min_r = min_razlika(s, n, a, t);

        if (s*min_r <= t) {
            resenje = s;
            razlika = s*min_r;
            l = s+1;
        } else {
            d = s-1;
        }
    }

    cout << resenje << ' ' << razlika << endl;

    return 0;
}