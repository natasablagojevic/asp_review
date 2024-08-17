#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<unordered_map>

int main()
{
  int n;
  std::cin >> n;

  std::vector<int> niz(n);

  for(int i = 0; i < n; i++){
    std::cin >> niz[i];
  }

std::unordered_map<int,int> m;

  int suf=0;
  for(int i = n - 1; i >= 0; i--) {
    suf += niz[i];
    m[suf] = i;
  }

  int pre = 0;
  int maxSum = INT_MIN;
  for(int i = 0; i < n; i++){
    pre += niz[i];

    if(m[pre] > i) {
      if(pre > maxSum)
        maxSum = pre;
    }
  }

  if(maxSum == INT_MIN){
      std::cout << 0 <<std::endl;
      return 0;
  } else {
      std::cout << maxSum << std::endl;
  }

return 0;
}
