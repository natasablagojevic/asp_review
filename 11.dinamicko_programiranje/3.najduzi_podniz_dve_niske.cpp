#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int nzp(string &a, string &b, int n, int m)
{
  if (n == 0 || m == 0)
    return 0;

  if (a[n-1] != b[m-1])
    return max(nzp(a,b,n,m-1), nzp(a, b, n-1, m));
  else 
    return 1 + nzp(a, b, n-1, m-1);
}

int main()
{
  string a, b;
  cin >> a >> b;

  int N = a.size();
  int M = b.size();

  vector<vector<int>> dp(N+1, vector<int>(M+1));

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      if (a[n-1] != b[m-1]) 
        dp[n][m] = max(dp[n-1][m], dp[n][m-1]);
      else 
        dp[n][m] = 1 + dp[n-1][m-1];
    }
  }

  cout << dp[N][M] << endl;



  return 0;
}