/*
 *	Zamena petlje formulom
 */

#include<iostream>

using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

	// I nacin:
    // [a, b]
    // int br = 0;
    // for (int i = a; i <=b; i++)
        // if (i % k == 0)
            // br++;

    // cout << br << endl;

    // II nacin:
    if (a == 0)
        cout << ((b/k) + 1) << endl;
    else
        cout << ((b/k) - ((a-1)/k)) << endl;

    return 0;
}
