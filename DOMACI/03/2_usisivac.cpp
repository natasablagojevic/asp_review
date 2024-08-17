#include <bits/stdc++.h>

using namespace std;

int n, m;
int cntALL = 0;

int solve(int i, int j, vector<vector<int>> &a, int cnt)
{

    if (a[i][j] == 2 && cnt == cntALL - 1)
        return 1;

    if (a[i][j] == 2)
        return 0;

    int retVal = 0;
    if (i + 1 < n && a[i + 1][j] != -1) {
        int temp = a[i][j];
        a[i][j] = -1;
        retVal += solve(i + 1, j, a, cnt + 1);
        a[i][j] = temp;
    }

    if (j + 1 < m && a[i][j + 1] != -1) {
        int temp = a[i][j];
        a[i][j] = -1;
        retVal += solve(i, j + 1, a, cnt + 1);
        a[i][j] = temp;
    }

    if (i - 1 >= 0 && a[i - 1][j] != -1) {
        int temp = a[i][j];
        a[i][j] = -1;
        retVal += solve(i - 1, j, a, cnt + 1);
        a[i][j] = temp;
    }

    if (j - 1 >= 0 && a[i][j - 1] != -1) {
        int temp = a[i][j];
        a[i][j] = -1;
        retVal += solve(i, j - 1, a, cnt + 1);
        a[i][j] = temp;
    }

    return retVal;
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int r, c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] == 1) {
                r = i;
                c = j;
            }

            if (a[i][j] != -1) {
                cntALL++;
            }
        }
    }

    cout << solve(r, c, a, 0) << endl;

    return 0;
}
