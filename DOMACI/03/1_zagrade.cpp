#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateParentheses(int open, int close, int n, int maxDepth, string current, vector<string>& result) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        generateParentheses(open + 1, close, n, maxDepth, current + "(", result);
    }

    if (close < open && close < maxDepth) {
        generateParentheses(open, close + 1, n, maxDepth, current + ")", result);
    }
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<string> validParentheses;
    generateParentheses(0, 0, n, d, "", validParentheses);

    // Sortiranje i ispis validnih nizova
    sort(validParentheses.begin(), validParentheses.end());
    for (const string& s : validParentheses) {
        cout << s << endl;
    }

    return 0;
}
