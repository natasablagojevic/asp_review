#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void ispisi(vector<int> &a)
{
  for (int x : a)
    cout << x << ' ';
  cout << endl;
}

/* VARIJACIJE BEZ PONAVLJANJA */
void varijacije(vector<int> &a, int n, vector<bool> upotrebljen, int i)
{
  if (i == a.size()) {
    ispisi(a);
    return ;
  }

  for (int x = 1; x <= n; x++) {
    if (!upotrebljen[x]) {
      a[x] = i;
      upotrebljen[x] = true;
      varijacije(a, n, upotrebljen, i+1);
      upotrebljen[x] = false;
    }
  }

}

int main()
{


  return 0;
}