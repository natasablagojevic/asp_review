#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int merge_sort(vector<int> &a, int l, int d, vector<int> &pom)
{
  if (l >= d)
    return 0;

  int s = (l+d)/2;

  int resL = merge_sort(a, l, s, b);
  int resD = merge_sort(a, s, d, b);
  int resU = 0; // unakrsno

  int j = l;
  for (int i = s; i < d; i++) {
    while (j < s && v[i] >= v[j]) 
      j++;

    resU += j - l;
  }

  merge(a.begin() + l, a.begin() + s, a.begin() + s, a.begin() + d);

  copy(pom.begin(), pom.begin() + (d-l), a.begin() + l);

  return resL + resD + resU;
}

int main()
{
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  vector<int> tmp(n);

  cout << merge_sort(v, 0, n, tmp) << endl; 


  return 0;
}