#include<iostream>
#include<vector>

using namespace std;

bool sledeca_permutacija(vector<int> &a)
{
  int n = a.size();
  int i = n-1;

  while (i >= 0 && a[i] > a[i+1]) 
    i--;

  if (i < 0)
    return false;

  int j = n-1;
  while (a[j] < a[i])
    j--;

  swap(a[i], a[j]);

  for (j = n-1, i++; i < j; i++, j--)
    swap(a[i], a[j]);
  
  return true;
}

int main()
{
  return 0;
}