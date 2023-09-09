#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) 
    cin >> v[i];

  sort(v.begin(), v.end());

  int zbir = 0;
  for (int i = 0; i < n/2; i++) {
    zbir -= v[i];
    zbir += v[n-1-i];
  }

  cout << (2*zbir) << endl; 

  return 0;
}