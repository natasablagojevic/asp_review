#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//                 size:k                 size:n+1,false            0
void varijacije(vector<int> &a, int n, vector<bool> &upotrebljen, int i)
{
  if (i == a.size()) {
    ispisi_niz(a);
    return ;
  }

  for (int x = 1; x <= n; x++) {
    if (!upotrebljen[x]) {
      a[i] = x;
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