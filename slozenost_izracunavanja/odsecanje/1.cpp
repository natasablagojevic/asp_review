#include<iostream>

using namespace std;

/* bool prost(int n)
{
    for (int i = 2; i < n/2; i++)
        if (n % i == 0)
            return false;

    return true;
} */

/* bool prost(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
} */

bool prost(int n)
{
    if (n == 1 || (n != 2 && n%2 == 0) || (n != 3 && n%3 == 0))
        return false;

    for (int i = 1; (6*i-1)*(6*i-1) <= n; i++)
        if (n % (6*i-1) == 0 || n % (6*i+1) == 0)
            return false;

    return true;
}

int main()
{
    int n;
    cin >> n;

    cout << (prost(n) == true ? "DA" : "NE") << endl;

    return 0;
}