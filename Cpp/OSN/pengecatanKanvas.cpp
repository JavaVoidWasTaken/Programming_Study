#include <iostream>
#include <vector>
#include <stdint.h>
#include <unordered_map>
#include <string>

using namespace std;
using ll = int64_t;

ll countTrue(unordered_map<ll, bool> x) {
    ll result = 0;
    for (auto i : x) {
        if (i.second) { ++result; }
    }
    return result;
}

int main() {
    ll M, N, K, temp;
    string type;
    unordered_map<ll, bool> row;
    unordered_map<ll, bool> collumn;

    cin >> M >> N >> K;

    for (ll i = 0; i < K; ++i) {
        cin >> type >> temp;
        if (type == "C") {
            if (collumn[temp]) {
                collumn[temp] = false;
            } else {
                collumn[temp] = true;
            }
        } else {
            if (row[temp]) {
                row[temp] = false;
            } else {
                row[temp] = true;
            }
        }
    }

    cout << (countTrue(collumn)*(M-countTrue(row)))+(countTrue(row)*(N-countTrue(collumn))); 
}   
