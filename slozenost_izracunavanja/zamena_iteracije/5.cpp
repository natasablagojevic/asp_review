#include<iostream>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;

    int br = 0;
    for (int m = 2; m + m*(m-1)/2 <= n; m++)
        if ((n - m*(m-1)/2)%m == 0)
            br++;

    cout << br << endl;

    return 0;
}