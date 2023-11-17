#include<iostream>

void ispisi(const int64_t &x)
{
  std::cout << x << std::endl;
} 

int main()
{
  int64_t n;
  std::cin >> n;
  

  int64_t a1 = n+1;
  int64_t n1 = n-2;
  int64_t n2 = n*n-1;
  int64_t sum = 0;

  int64_t ukupna_suma = (n2*(n2+1))/2;
  ispisi(a1);
  ispisi(n1);
  ispisi(n2);
  ispisi(ukupna_suma);

  for (int64_t i = 0; i < n1; i++) {
    sum += (n1*(2*a1 + n1-1))/2;
    a1 += n;
    std::cout << "------------------" << std::endl;
    std::cout << i << ':' << sum << ", a1: " << a1 << std::endl;

  }

  std::cout << sum << std::endl;

  std::cout << ukupna_suma - sum << std::endl;

  

  return 0;
}
