#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void ispisi(vector<int> &p, int j)
{
  for (int i = 0; i < j; i++)
    cout << p[i] << ' ';
  cout << endl;
}

void svi_podskupovi(vector<int> &a, int i, vector<int> &p, int j)
{
  if (i == a.size()) {
    ispisi(p, j);
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