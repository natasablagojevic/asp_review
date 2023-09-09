#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<vector<int>> matrica(n, vector<int>(n));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> matrica[i][j];

  vector<vector<int>> dp(N+1, vector<int>(N+1));

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= N; n++) {
      dp[n][m] = max(dp[n-1][m], dp[n][m-1]) + dp[n-1][m-1];
    }
  } 

  cout << dp[N][M] << endl;

  return 0;
}