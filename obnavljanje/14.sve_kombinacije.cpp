#include<iostream>
#include<vector>

using namespace std;

void ispisi(vector<int> &a)
{
  for (int x : a)
    cout << x << ' ';
  cout << endl;
}

void sve_kombinacije(vector<int> &a, int i, int n)
{
  int k = a.size();

  if (i == k) {
    ispisi(a);
    return ;
  }

  int pocetak = i == 0 ? 1 : a[i-1] + 1;
  for (int x = pocetak; x <= n; x++) {
    a[i] = x;
    sve_kombinacije(a, i+1, n);
  }
}

int main()
{

  return 0;
}