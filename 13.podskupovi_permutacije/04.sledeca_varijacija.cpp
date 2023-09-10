#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sledeca_varijacija(int n, vector<int> &v)
{
  int k = v.size();

  for (int i = k-1; i >= 0 && v[i] == n; i--)
    v[i] = 1;

  if (i < 0)
    return false;
  
  v[i]++;
  return true;
}

int main()
{
  int k, n;
  cin >> k >> n;

  vector<int> v(k);
  for (int i = 0; i < k; i++)
    cin >> v[i];

  sledeca_varijacija(n, v);

  for (int x : v)
    cout << x << ' ';
  cout << endl;


  return 0;
}