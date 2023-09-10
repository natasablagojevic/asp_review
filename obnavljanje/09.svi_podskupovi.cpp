#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void obradi(vector<int> &p, int k)
{
  for (int i = 0; i < k; i++)
    cout << p[i] << ' ';
  cout << endl;
}

/* LEKSIKOGRAFSKI */
void svi_podskupovi(int n, vector<int> &p, int k)
{
  obradi(p, k);

  int pocetak = k == 0 ? 0 : p[k-1] + 1;
  for (int i = pocetak; i < n; i++) {
    p[k] = i;
    svi_podskupovi(n, p, k+1);
  }
}

void svi_podskupovi(vector<int> &a, int i, vector<int> &p, int j)
{
  if (i == (int)a.size()) {
    obradi(p, j);
    return ;
  }

  svi_podskupovi(a, i+1, p, j);
  p[j] = a[i];
  svi_podskupovi(a, i+1, p, j+1);
}

int main()
{


  return 0;
}