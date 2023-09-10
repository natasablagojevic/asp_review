#include<iostream>
#include<vector>

using namespace std;

void ispisi(vector<int> &a)
{ 
  for (int x : a)
    cout << x << ' ';
  cout << endl;
}

void sve_permutacije(vector<int> &a, int n, vector<int> &upotrebljen, int i)
{
  if (i == a.size()) {
    ispisi(a);
    return ;
  }

  for (int x = 1; x <= n; x++) {
    if (!upotrebljen[x]) {
      a[i] = x;
      upotrebljen[x] = true;
      sve_permutacije(a, n, upotrebljen, i+1);
      upotrebljen[x] = false;
    }
  }
}

int main()
{

  return 0;
}