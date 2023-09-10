#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sve_kombinacije(vector<int> &a, int i, int n)
{
  int k = a.size();

  if (i == k) {
    ispisi_niz(a);
    return ;
  }

  int pocetak = i == 0 ? 1 : a[i-1] +1;
  int kraj = n - k + i +1;

  for (int x = pocetak; x <= kraj; x++) {
    a[i] = x;
    sve_kombinacije(a, i+1, n);
  }
}

int main()
{



  return 0;
}