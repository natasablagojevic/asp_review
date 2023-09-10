#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void ispisi(vector<int> &v)
{
  for (int x : v)
    cout << x << ' ';
  cout << endl;
}

/* VARIJACIJE SA PONAVLJANJEM DUZINE K */
void sve_varijacije(int k, int n, vector<int> &v)
{
  if (k == 0) {
    ispisi(v);
    return ;
  }

  for (int i = 1; i <= n; i++) {
    v[v.size()-k] = i;
    sve_varijacije(k-1, n, v);
  }
}

void sve_varijacije(int n, vector<int> &v, int m)
{
  if (m == v.size()) {
    ispisi(v);
    return ;
  }

  for (int i = 1; i <= n; i++) {
    v[m] = i;
    sve_varijacije(n, v, m + 1);
  }
}


int main()
{


  return 0;
}