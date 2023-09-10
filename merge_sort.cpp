
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge_sort(vector<int> &a, int l, int d, vector<int> &pom)
{
  if (l >= d)
    return ;

  int s = (l+d)/2;

  merge_sort(a, l, s, pom);
  merge_sort(a, s+1, d, pom);

  int i = l, j = s+1, k = 0;
  while (i <= s && j <= d) 
    if (a[i] < a[j])
      pom[k++] = a[i++];
    else 
      pom[k++] = a[j++];

  while (i <= s)
    pom[k++] = a[i++];

  while (j <= d)
    pom[k++] = a[j++];

  for (int i = l, k = 0; i <= d; i++, k++)
    a[i] = pom[k];
}

int main()
{



  return 0;
}