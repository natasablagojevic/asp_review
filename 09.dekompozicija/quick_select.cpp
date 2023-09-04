#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swap(vector<int> &a, int i, int j)
{
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int l = 0, d = n-1; // [l,d]
  
  // s = gde se nalazi poslednji element koji je <= pivota
  /* 
    [l,s] <= pivota svi elementi
    [s,i] > pivota svi elementi
    [i,d] ?
   */
  
  while (l <= d) {
    // particionisi niz u odnosu na neki pivot
    // pivot se nakon toga nalazi na poziciji S

    int s = l;
    for (int i = l+1; i <= d; i++) {
      if (v[i] >= v[l]) 
        swap(v[i], v[++s]);
      swap(v[l], v[s]);
    }


    if (s < k) 
      l = s+1;
    else if (s > k) 
      d = s-1;
    else 
      break;

  }

  int sum = 0;
  for (int i = 0; i < k; i++)
    sum += v[i];

  cout << sum << endl;

  return 0;
}