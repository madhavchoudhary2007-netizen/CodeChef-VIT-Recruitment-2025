#include <iostream>
#include <algorithm>
#include <cmath>

// Keeping __int128 for the huge intermediate values
typedef __int128 int128;

// I like having my own small input reader, even though std::cin >> x is fine.
static long long grab_ll() {
    long long v;
    std::cin >> v;
    return v;
}

// gcd for int128
int128 gcd128(int128 a, int128 b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// Count trailing zeros in a binary int128 (factors of 2).
// Very tiny loop, basically O(log n) but n is big; still trivial.
long long count_tz(int128 x) {
    if (x == 0) return 0;
    long long c = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        ++c;
    }
    return c;
}

// Find smallest k where 2^k >= n.
// Using shifts rather than logs to avoid floating precision issues.
long long next_pow2_exp(int128 n) {
    if (n == 0) return 0;

    long long k = 0;
    int128 t = n;
    // basically computing floor(log2(n))
    t >>= 1;
    while (t > 0) {
        t >>= 1;
        ++k;
    }

    // verify exponent really fits
    if ( ((int128)1 << k) < n ) {
        ++k;
    }
    return k;
}

// main logic for each testcase
void solve() {

    
    long long cr_n = grab_ll();
    long long cr_d = grab_ll();
    long long sr_n = grab_ll();
    long long sr_d = grab_ll();
    long long sh_n = grab_ll();
    long long sh_d = grab_ll();

    // Compute the cross-multiplied volumes.
    // A = 2 * cr_n^3 * sr_d^2 * sh_d
    // B = 3 * cr_d^3 * sr_n^2 * sh_n
    int128 A = (int128)2 * cr_n * cr_n * cr_n * sr_d * sr_d * sh_d;
    int128 B = (int128)3 * cr_d * cr_d * cr_d * sr_n * sr_n * sh_n;

    if (A == 0 || B == 0) {
        // trivial case: one side has no volume
        std::cout << "0\n";
        return;
    }

    // reduce ratio A:B using gcd
    int128 g = gcd128(A, B);
    A /= g;
    B /= g;

    if (A == B) {
        // already matched
        std::cout << "0\n";
        return;
    }

    // find max exponent needed
    int128 bigger = (A > B ? A : B);
    long long K = next_pow2_exp(bigger);

    // figure out cuts
    long long cuts_cap  = K - count_tz(B);
    long long cuts_stem = K - count_tz(A);

    
    long long answer = cuts_cap + cuts_stem;

    std::cout << answer << "\n";

    // leftover optional debug block:
    // std::cerr << "A=" << (long long)A << " B=" << (long long)B << " K=" << K << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
