#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int akcije(vector<int> &a, int l, int d, int &vmax, int &vmin) 
{
  if (l == d) {
    vmax = vmin = a[l];
    return 0;
  }

  int s = (l+d)/2;

  int maxL;
  int minL;
  int resL = akcije(a, l, s, maxL, minL);

  int maxD;
  int minD;
  int resD = akcije(a, s+1, d, maxD, minD);

  vmax = max(maxL, maxD);
  vmin = min(minL, minD);

  return max({resL, resD, maxD - minD});
}

int main()
{
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int vmax, vmin;
  cout << akcije(v, 0, n-1, vmax, vmin) << endl;

  return 0;
}