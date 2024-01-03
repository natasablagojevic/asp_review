#include <iostream>
#include <vector>
using namespace std;

void generateParentheses(int open, int close, int n, int depth, string current) {
    if (depth == 0) {
        if (open == n && close == n) {
            cout << current << endl;
        }
        return;
    }

    if (open < n) {
        generateParentheses(open + 1, close, n, depth - 1, current + "(");
    }

    if (close < open) {
        generateParentheses(open, close + 1, n, depth - 1, current + ")");
    }
}

int main() {
    int n, d;
    cin >> n >> d;

    generateParentheses(0, 0, n, d, "");

    return 0;
}
