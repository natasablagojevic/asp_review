#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    //  a je manja stranica

    if (a > b)
        swap(a, b);

    if (a + c <= b)
        a += c;
    else {
        int preostalo = c - (b - a);
        a = b + preostalo/2;
        b = b + (preostalo + 1)/2;
    }

    cout << a*b << endl;


    return 0;
}