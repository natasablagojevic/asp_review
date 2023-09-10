#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sledeca_varijacija(int n, vector<int> &v)
{
  int k = v.size();
  int i;

  for (i = k-1; i >= 0 && v[i] == n; i--)
    v[i] = 1;

  if (i < 0)
    return false;

  v[i]++;
  return true;
}

int main()
{

  return 0;
}