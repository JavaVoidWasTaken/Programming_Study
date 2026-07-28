#include <iostream>
#include <stdint.h>
#include <string>

using namespace std;
using ll = int64_t;

int main() {
    string telur;
    ll bebek = 0, ayam = 0, result = 0;

    cin >> telur;

    for (char i : telur) {
        if (i == 'A') { ayam++; }
        else { bebek++; }
    }

    while (bebek >= 3) {
        if (ayam >= 1) {
            bebek -= 3;
            ayam -= 1;
            ++result;
        } else if (bebek >= 4) {
            bebek -= 4;
            ++result;
        } else {
            break;
        }
    }
    
    cout << result;
}
