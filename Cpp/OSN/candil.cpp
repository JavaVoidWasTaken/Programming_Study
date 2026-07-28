#include <iostream>
#include <stdint.h>

using namespace std;
using ll = int64_t;

int main() {
    ll bebek, candil;

    cin >> bebek >> candil;
    
    if (candil <= bebek) {
        cout << 0;
    } else {
        cout << candil%bebek;
    }
}
