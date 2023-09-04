#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge_sort(vector<int> &a, int l, int d, vector<int> &pom)
{
  if (l >= d)
    return ;

  int s = (l+d)/2;

  merge_sort(a, l, s, b);
  merge_sort(a, s, d, b);


  int i = l, j = s, k = s+1;

  merge(a.begin() + l, a.begin() + s, a.begin() + s, a.begin() + d);

  copy(pom.begin(), pom.begin() + (d-l), a.begin() + l);
}

int main()
{
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  


  return 0;
}