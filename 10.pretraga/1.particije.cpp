#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

/* PRVI PRISTUP */
void particije(int n, int maxSabirak, vector<int> &particija)
{
  if (n == 0) {
    for (int x : particija)
      cout << x << ' ';
    cout << endl;
    return ;
  }

  for (int sabirak = 1; sabirak <= min(maxSabirak, n); sabirak++) {
    
    particija.push_back(sabirak);
    
    particije(n-sabirak, sabirak, particija);

    particija.pop_back();
  }
}

/* DRUGI PRISTUP */
void particije2(int n, int maxSabirak, vector<int> &particija)
{
  if (n == 0) {
    for (int x : particija)
      cout << x << ' ';
    cout << endl;
    return ; 
  }

  if (maxSabirak > 1)
    particije2(n, maxSabirak - 1, particija);
  
  if (maxSabirak <= n) {
    particija.push_back(maxSabirak);
    particije2(n - maxSabirak, maxSabirak, particija);
    particija.pop_back();
  }
}

void particije2p(int n, int maxSabirak, int i, vector<int> &particija)
{
  if (n == 0) {
    for (int x : particija)
      cout << x << ' ';
    cout << endl;
    return ; 
  }

  if (maxSabirak > 1)
    particije2p(n, maxSabirak - 1, particija);
  
  if (maxSabirak <= n) {
    // particija.push_back(maxSabirak);
    particija[i] = maxSabirak;
    particije2p(n - maxSabirak, maxSabirak, i+1, particija);
    // particija.pop_back();
  }
}

int main()
{
  int n;
  cin >> n;

  vector<int> particija;
  particije(n, n, particija);


  return 0;
}