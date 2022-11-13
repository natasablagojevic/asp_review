#include<iostream>

using namespace std;

int nzd(int a, int b)
{
    int tmp;
    while (b) {
        tmp = a%b;
        a = b;
        b = tmp;
    }

    return a;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << nzd(a, nzd(b, c)) << endl;


    return 0;
}