#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sledeca_kombinacija(int k, int n, vector<int> &a)
{
  int i = k-1;

  while (a[i] == n-k+1+i)
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