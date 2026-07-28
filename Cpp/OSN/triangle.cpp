#include <iostream>
#include <stdint.h>

using namespace std;
using ll = int64_t;

int main() {
    ll size;
    ll sum = 0;

    cin >> size;
    
    if (size == 0 || size == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i <= size; ++i) {
        cout << i << ' ' << sum << '\n';
        sum += i;
    }
}
