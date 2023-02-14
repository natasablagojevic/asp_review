#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int max_sum = 0, sum = 0;
  for (int i = 0; i < k; i++) {
    sum += i*a[i];
  }
  max_sum = sum;
  for (int i = k; i < n; i++) {
    sum += i*a[i] - (i-k)*a[i-k];
    max_sum = max(max_sum, sum);
  }
  cout << max_sum << endl;
  return 0;
}
