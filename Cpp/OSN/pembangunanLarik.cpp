#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;
using ll = int64_t;

// Inclusive. Returns a vector containing the start of non-zero indexes.
vector<ll> modify(vector<ll> &list, ll l, ll v, ll r) {
    ll start = l; vector<ll> startIndexes;
    for (int i = l; i <= r; ++i) {
        list[i] -= v;
        if (list[i] < 0) { throw -1; }
        if (list[i] == 0) { startIndexes.push_back(start); }
    }
}

bool isValid(vector<ll> list) {
    for (auto i : list) { if (i != 0) { return false; } }
    return true;
}

int main() {
    ll N, temp;
    vector<ll> list;

    cin >> N;

    cin >> temp;
    ll min = temp;
    list.push_back(temp);

    for (int i = 0; i < N-1; ++i) {
        cin >> temp;
        if (min > temp) { min = temp; };
        list.push_back(temp);
    }
    
    modify

    for (int i = 0; i < N; ++i) {
        
        
}


