#include<iostream>
#include<vector>
#include<numeric>
#include<limits>

using namespace std;

vector<uint64_t> memo;

uint64_t broj_dekodiranja_memo(string &s, int n)
{
  if (memo[n] != -1)
    return memo[n];

  if (n <= 1)
    return memo[n] = 1;

  int br1 = s[n-1] - '0';
  int br2 = (s[n-2] - '0')*10 + s[n-1] - '0';

  uint64_t br = 0;

  if (b1 != 0)
    br += broj_dekodiranja(s, n-1);
  
  if (b2 >= 10 && b2 <= 26)
    br += broj_dekodiranja(s, n-2);

  return memo[n] = br;
}

uint64_t broj_dekodiranja(string &s, int n)
{
  if (n <= 1)
    return 1;

  int br1 = s[n-1] - '0';
  int br2 = (s[n-2] - '0')*10 + s[n-1] - '0';

  uint64_t br = 0;

  if (b1 != 0)
    br += broj_dekodiranja(s.size()+1, -1);
  
  if (b2 >= 10 && b2 <= 26)
    br += broj_dekodiranja(s, n-2);

  return br;
}

int main()
{
  string s;
  cin >> s;

  memo = vector<uint64_t>(s, n+1);

  cout << broj_dekodiranja(s, s.size()) << endl;

  int N = s.size();

  vector<uint64_t> dp(N+1);
  dp[0] = dp[1] = 0;

  for (int n = 2; n <= N; n++) {
    int br1 = s[n-1] - '0';
    int br2 = (s[n-2] - '0')*10 + s[n-1] - '0';
    
    if (b1 != 0)
      dp[n] += dp[n-1];
    
    if (b2 >= 10 && br2 <= 26)
      dp[n] += dp[n-2];
  }

  cout << dp[N] << endl;

  return 0;
}