#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void obradi(vector<int> &p, int k)
{
  for (int i = 0; i < k; i++) 
    cout << p[i] << ' ';
    cout << endl;
}

void svi_podskupovi(int n, vector<int> &p, int k)
{
  obradi(p, k);

  int pocetak = k == 0 ? 0 : p[k-1]+1;

  for (int i = pocetak; i < n; i++) {
    p[k] = i;
    svi_podskupovi(n, p, k+1);
  }
}

int main()
{


  return 0;
}