#include <iostream>
#include <vector>

void solve_case() {
    int n;
    std::cin >> n;

 
    std::vector<int> arr;
    arr.reserve(n);

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    // Edge-case bailout AFTER reading.
    if (n <= 2) {
        std::cout << n << "\n";
        return;
    }

    // sliding window stuff
    int win_start = 0;

    // fruit "types" I am tracking
    int recent = -1;        // most recent fruit type
    int older = -1;         // the other one in the window
    int recent_run_start = 0;  // where the run of "recent" started

    int best = 0;

    // I might remove this later
    int tmp_len = 0;

    for (int i = 0; i < n; ++i) {
        int f = arr[i];

        if (f == recent) {
            // nothing special, same fruit as before
        }
        else if (f == older) {
            // swap types: "recent" should always be recent
            older = recent;
            recent = f;
            recent_run_start = i;
        }
        else {
            // new fruit type detected
            if (older != -1) {
                // shift window to keep only last two types
                win_start = recent_run_start;
            }

            // redo the type tracking
            older = recent;
            recent = f;
            recent_run_start = i;
        }

        // calculate window length; doing it manually instead of std::max
        tmp_len = i - win_start + 1;
        if (tmp_len > best) {
            best = tmp_len;
        }

        /* 
        // Random old idea I tried:
        // if (i > 0 && arr[i] == arr[i-1]) { ... }
        // but decided it was pointless. Keeping as a note.
        */
    }

    std::cout << best << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); // no sync with stdout

    int t;
    std::cin >> t;

    // loop through testcases
    while (t--) {
        solve_case();
    }

    return 0;
}