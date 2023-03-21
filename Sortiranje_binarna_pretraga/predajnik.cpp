#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>

using namespace std;

int main()
{
    // zone i sirina zona
    int n;
    cin >> n;

    vector<double> zone(n);
    for (int i = 0; i < n; i++)
        cin >> zone[i];

    vector<double> poluprecnik(n+1);
    poluprecnik[0] = zone[0];
    for (int i = 1; i < n; i++)
        poluprecnik[i] = poluprecnik[i-1] + zone[i];

    int m;
    cin >> m;

    // O(m)
    while (m--) {
        double x, y;
        cin >> x >> y;

        double d = sqrt(x*x + y*y);

        /* 
            Binarna pretraga, nalazi prvi broj >= od datog broja koji je prosledjen 
            kao parametar funkcije. Ako takav element ne postoji dobijamo a.end()
         */
        auto it = lower_bound(poluprecnik.begin(), poluprecnik.end(), d); // O(logn)

        if (it != poluprecnik.end())
            cout << it - poluprecnik.begin() << endl;
        else 
            cout << "izvan" << endl;
    }
    // O(m*logn + n)    

	return 0;
}
