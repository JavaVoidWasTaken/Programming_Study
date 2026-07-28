#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using ll = int64_t;
using namespace std;

ll diff(ll x, ll y) {
    ll result = x-y;
    if (result < 0) {
        return result*-1;
    }
    return result;
}

int main() {
    ll size, temp;
    vector<ll> list;
    vector<ll> sorted;
    unordered_map<ll, ll> map;

    cin >> size;

    for (ll i = 0; i < size; ++i) {
        cin >> temp;
        list.push_back(temp);
    }

    sorted = list;
    sort(sorted.begin(), sorted.end());
    
    for (ll i = 0; i < size; ++i) {
        map[list[i]] = max(diff(list[i], sorted[0]), diff(list[i], sorted[size-1]));
    }

    for (ll i = 0; i < size; ++i) {
        cout << map[list[i]] << '\n';
    }
}
