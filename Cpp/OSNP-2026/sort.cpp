#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = int64_t;

int main() {
    ll size, temp;
    vector<ll> list;

    cin >> size;

    for (ll i = 0; i < size; ++i) {
        cin >> temp;
        list.push_back(temp);
    }

    sort(list.begin(), list.end());

    for (auto i : list) { cout << i << ' '; }
}
