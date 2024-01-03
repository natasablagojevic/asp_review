#include <iostream>
#include<vector>

int maxSum(const std::vector<int> &vec, const int &a, const int &b)
{
    int n = vec.size();

    std::vector<int> prefiksna_suma(n+1, 0);
    for (int i = 0; i < n; i++)
        prefiksna_suma[i+1] = prefiksna_suma[i] + vec[i];

    int max_sum = 0;
    for (int i = 0; i <= n - b; i++) {
        int suma_prvih = prefiksna_suma[i] - prefiksna_suma[0];
        int suma_trecih = prefiksna_suma[n] - prefiksna_suma[i + b - a];

        max_sum = std::max(max_sum, std::min(suma_prvih, suma_trecih));
    }

    return max_sum;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    int a, b;
    std::cin >> a >> b;

    std::cout << maxSum(vec, a, b) << std::endl;


    return 0;
}
