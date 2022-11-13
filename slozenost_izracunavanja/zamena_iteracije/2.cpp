#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    int pom = n;

    while (pom--) {
        int x;
        cin >> x;
        sum += x;
    }

    int sum_of_n = n*(n+1)/2;

    cout << (sum_of_n - sum) << endl;
    

    return 0;
}