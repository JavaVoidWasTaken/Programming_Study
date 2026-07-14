#include <iostream>
#include <numeric>
#include <stdint.h>
using namespace std;
using ll = int64_t;

int main() {
    ll a, b, c, d; // Input
    ll A, B, C, D; // Equalized fractions
    ll E, F; // Results
    ll commonFactor;

    cin >> A >> B >> C >> D;

    a = A*D;
    b = B*D;
    c = C*B;
    d = D*B;

    E = a+c;
    F = b;

    while (true) {
        commonFactor = gcd(E, F);
        if (commonFactor == 0 || commonFactor == 1) {
            break;
        }
        E /= commonFactor;
        F /= commonFactor;
    }

    cout << E << ' ' << F << '\n';
}
