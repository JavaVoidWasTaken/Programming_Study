#include <iostream>
#include <stdint.h>
#include <cmath>

using namespace std;
using ll = int64_t;

ll ceilDivision(ll number, ll divisor) {
    return (number+(number%divisor) == 0 ? 0 : 1) / divisor;
}

int main() {
    int N, P, L;

    cin >> N >> P >> L;

    ll left = 1;
    ll totalSize = N*P*L;
    ll right = totalSize*2;
    ll middle = (left+right)/2;
    
    while (left <= right) {
        if (ceilDivision(N*P, middle) <= middle && ceilDivision(N*P, middle) <= middle) {
            if (totalSize < middle*middle) {
                if (middle-1 > 0 && totalSize < (middle-1)*(middle-1)) {
                    right = middle-1;
                }
            }
        }

        --middle;
    }
    
    cout << middle;
}
