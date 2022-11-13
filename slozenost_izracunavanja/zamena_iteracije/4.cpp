#include<iostream>

using namespace std;

int main()
{
    int64_t a, b, k;
    cin >> a >> b >> k;

    int64_t l = a % k == 0 ? a/k : a/k +1;
    int64_t d = b/k;

    cout << (d >= l ? d-l+1 : 0) << endl;

    return 0;
}