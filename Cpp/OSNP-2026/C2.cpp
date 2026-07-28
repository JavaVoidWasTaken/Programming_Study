#include <iostream>
#include <stdint.h>

using namespace std;
using ll = int64_t;

ll counter = 0;

void solve(ll n, int depth) {
    ++counter;
    if (depth == 3) { return; }

    for (int i = n+1; i <= n*2; ++i) {
        solve(i, depth+1);
    }
}
    

int main() {
    for (int i = 0; i < 3; ++i) {
        solve(4, i);
        cout << counter-1 << endl;
        counter = 0;
    }
}
