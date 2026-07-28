#include <iostream>
#include <stdint.h>

using namespace std;
using ll = int64_t;

ll factorial(ll val) {
    ll result = 1;
    for (int i = 1; i <= val; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    ll size;

    cin >> size;

    ++size;

    cout << (size*(size-1))/2;
}
