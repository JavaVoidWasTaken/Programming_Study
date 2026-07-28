#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;
using ll = int64_t;

int main() {
    ll size, temp;
    vector<ll> kota;
    ll result = 0;
    ll min = -1;

    cin >> size;

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        if (min == -1) { min = temp; }
        else if (temp < min) { min = temp; }
        kota.push_back(temp);
    }

    for (auto i : kota) { result += i + min; }

    result -= min*2;

    cout << result;
}


