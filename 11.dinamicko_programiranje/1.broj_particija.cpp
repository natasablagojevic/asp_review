#include<iostream>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

// broj particija ne moze biti negativan
// odozgo nanize
vector<vector<int>> memo(n+1, vector<int>(n+1, -1)); 


int broj_particija1(int n, int max_sabirak)
{
  if (memo[n][max_sabirak] != -1)
    return memo[n][max_sabirak];

  if (n == 0)
    return memo[n][max_sabirak] = 1;

  int br = 0;
  if (max_sabirak > 1)
    br += broj_particija1(n, max_sabirak - 1);
  
  if (max_sabirak <= n)  
    br += broj_particija1(n - max_sabirak, max_sabirak);

  return memo[n][max_sabirak] = br;
}


int broj_particija(int n, int max_sabirak)
{
  if (n == 0)
    return 1;

  int br = 0;
  if (max_sabirak > 1)
    br += broj_particija(n, max_sabirak - 1);
  
  if (max_sabirak <= n)  
    br += broj_particija(n - max_sabirak, max_sabirak);

  return br;
}

int main()
{
  int n;
  cin >> n;

  cout << broj_particija(n, n) << endl;
  
  vector<vector<int>> dp(n+1, vector<int>(n+1)); 

  // postavi prvu vrstu na sve jedinice
  dp[0] = vector<int>(n+1, 1);

  for (int i = 1; i < n+1; i++) {
    for (int max_sabirak = 1; max_sabirak < n+1; max_sabirak++) {
      
      if (max_sabirak > 1)
        dp[i][max_sabirak] += dp[i][max_sabirak - 1];
      
      if (max_sabirak <= i)
        dp[i][max_sabirak] += dp[i - max_sabirak][max_sabirak];
    }
  }

  // na polju (n,n) se nalazi resenje zadatka
  cout << dp[n][n] << endl;

  return 0;
}