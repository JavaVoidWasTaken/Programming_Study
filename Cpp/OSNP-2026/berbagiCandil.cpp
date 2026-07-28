#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int64_t;

int main() {
    ll size, bebek, temp, best = -1;
    vector<ll> toko; 

    cin >> size >> bebek;

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        toko.push_back(temp);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((toko[i]+toko[j]) % bebek == 0) {
                if (best < toko[i]+toko[j]) {
                    best = toko[i]+toko[j];
                }
            }
        }
    }

    cout << best;
}
