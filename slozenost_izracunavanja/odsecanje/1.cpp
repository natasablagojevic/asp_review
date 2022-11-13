#include<iostream>

using namespace std;

bool prost(int n)
{
    for (int i = 2; i < n/2; i++)
        if (n % i == 0)
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