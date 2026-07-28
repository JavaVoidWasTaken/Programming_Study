#include <iostream>
#include <unordered_map>
#include <stdint.h>

using namespace std;
using ll = int64_t;

int main() {
    int size = 10; 
    unordered_map<ll, ll> list;

    for (int i = 0; i < 10; ++i) { list[i] += i*i; }

    for (auto i : list) { cout << i.first << ' ' << i.second  << endl; }
}

