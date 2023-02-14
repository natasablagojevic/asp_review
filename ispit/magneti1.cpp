#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  
  std::vector<int> kuglice(n);
  for (int i = 0; i < n; i++) {
    std::cin >> kuglice[i];
  }
  
  int sum = 0;
  int max_sum = 0;
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = i; j < n && j < i + k; j++) {
      sum += kuglice[j];
    }
    max_sum = std::max(max_sum, sum);
  }
  
  std::cout << max_sum << std::endl;
  
  return 0;
}
