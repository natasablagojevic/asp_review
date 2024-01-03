#include <iostream>
#include <string>

void generisanje(int d, int maxD, std::string &s, int i)
{
    int n = s.size();

    if (i == n) {
        std::cout << s << std::endl;
    } else {
        if (d < maxD && n - i - 1 >= d) {
            s[i] = '(';
            generisanje(d+1, maxD, s, i+1);
        }
        if (d > 0) {
            s[i] = ')';
            generisanje(d-1, maxD, s, i+1);
        }
    }
}

int main()
{
    int n, d;
    std::cin >> n >> d;

    std::string s(n , ' ');

    generisanje(0, d, s, 0);

    return 0;
}