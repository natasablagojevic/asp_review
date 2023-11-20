#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>

void napravi_drvo(const std::vector<int> &a, std::vector<int> &drvo, int k, int x, int y, const int &n)
{
    if (x == y) {
        if (n % a[x] == 0)
            drvo[k] = 1;
        else 
            drvo[k] = 0;

        return ;
    }

    int s = (x+y)/2;

    napravi_drvo(a, drvo, 2*k, x, s, n);
    napravi_drvo(a, drvo, 2*k+1, s+1, y, n);

    drvo[k] = drvo[2*k] + drvo[2*k+1];
}

int segment(std::vector<int> &drvo, int k, int x, int y, int a, int b)
{
    if (x > b || y < a)
        return 0;

    if (x >= a && y <= b)
        return drvo[k];

    int s = (x+y)/2;

    return segment(drvo, 2*k, x, s, a, b) + segment(drvo, 2*k+1, s+1, y, a, b);
}

int main()
{   
    int k, n;
    std::cin >> k >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i];

    int m;
    std::cin >> m;

    int h = (int)ceil(log2(n));
    int N = pow(2, h+1);
    std::vector<int> drvo(N, 0);

    napravi_drvo(a, drvo, 1, 0, n-1, k);
    
    // for (int x : drvo)
    //     std::cout << x << ' ';
    // std::cout << std::endl;

    int x, y;
    while (m--) {
        std::cin >> x >> y;
        std::cout << segment(drvo, 1, 0, n-1, x, y) << std:: endl;
    }


    return 0;
}