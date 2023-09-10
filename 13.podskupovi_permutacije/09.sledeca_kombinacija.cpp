#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool sledeca_kombinacija(int n, int k, vector<int> &a)
{
  int i = k - 1;

  while (a[i] == n - k + i + 1)
    i--;

  if (i < 0)
    return false;

  a[i]++;

  for (int x = i+1; x < k; x++)
    a[x] = a[i] + x - i;

  return true;
}

int main()
{


  return 0;
}