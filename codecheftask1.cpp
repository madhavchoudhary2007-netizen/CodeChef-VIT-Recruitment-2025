#include <iostream>
#include <string>

void solve() {
    std::string singularWord;
    std::cin >> singularWord;

    int len = singularWord.length();

    // The logic is simple: change the suffix "us" to "oi".
    // We access the characters directly by index.
    if (len >= 2) {
        singularWord[len - 2] = 'o';
        singularWord[len - 1] = 'i';
    }

    std::cout << singularWord << "\n";
}

int main() {
    // Fast I/O for speed
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int testCases;
    if (std::cin >> testCases) {
        while (testCases--) {
            solve();
        }
    }
    return 0;
}