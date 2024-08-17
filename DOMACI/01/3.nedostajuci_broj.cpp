#include<iostream>
#include<vector>
#include<algorithm>

int pronadji_broj(const std::vector<int> &a, const int &k)
{
  int l = 0;
  int d = a.size()-1;
  int nedostajuci = 0;

  while (l <= d) {
    int s = (l+d)/2;

    int ocekivani = a[s] - s - 1;

    if (ocekivani < k) {
      nedostajuci = a[s] + k - ocekivani;
      l = s + 1;
    } else {
      d = s - 1;
    }
  }

  return nedostajuci;
}

int main()
{
  int n, m;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  std::cin >> m;

  for (int i = 0; i < m; i++) {
    int k;
    std::cin >> k;

    std::cout << pronadji_broj(a, k) << std::endl;
  }

  return 0;
}