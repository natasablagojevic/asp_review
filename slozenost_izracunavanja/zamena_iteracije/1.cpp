#include<iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int brojac = 0;
    for (char x : s)
        if (x == '1')
            brojac++;

    cout << (brojac * (brojac - 1)/2) << endl;

    return 0;
}