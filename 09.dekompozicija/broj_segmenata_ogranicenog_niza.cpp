#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int prebroj(vector<int> &a, int l, int d, int t, vector<int> &tmp)
{
  if (d - l <= 1) 
    return 0;

  int s = (l+d)/2;

  int resL = prebroj(a, l, s, t, tmp);
  int resD = prebroj(a, s, d, t, tmp);

  int resU = 0;
  int j = l;
  for (int i = s; i < d; i++) {
    while (j < s && v[i] - v[j] > t) 
      j++;

    resU += s-j;
  }

  merge(a.begin() + l, a.begin() + s, a.begin() + s, a.begin() + d, tmp);

  copy(tmp.begin(), tmp.begin() + (d - l), a.begin() + l);

  return resL + resD + resU;
}

int main()
{
  int t, n;
  cin >> t >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> ap(n+1);
  partial_sum(a.begin(), a.end(), ap.begin());

  vector<int> tmp(n+1)
  cout << prebroj(ap, 0, n+1, t, tmp) << endl;


  return 0;
}