#include<iostream>
#include<vector>

using namespace std;

void eratosten(vector<bool> &prost, int n)
{
    prost.resize(n+1, true);
    prost[0] = prost[1] = false;    // brojevi 0 i 1 nisu prosti

    for (int i = 2; i*i <= n; i++)
        if (prost[i]) {
            for (int j = i*i; j <= n; j += i)
                prost[j] = false;
        }
}

int prost_u_intervalu(int a, int b)
{
    vector<bool> prost;
    eratosten(prost, b);

    int sum = 0;
    for (int i = a; i <= b; i++)
        if (prost[i])
            sum++;

    return sum;
}

int main()
{   
    int a, b;
    cin >> a >> b;

    cout << prost_u_intervalu(a, b) << endl;

    return 0;
}