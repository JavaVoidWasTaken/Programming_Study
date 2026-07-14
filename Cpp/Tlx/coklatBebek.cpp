#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = int64_t;

int main() {
    ll N, D, temp;
    ll bebekSenang = 0;
    pair<ll, ll> tempPair;
    vector<pair<ll, ll>> bebek;
    cin >> N >> D;

    for (ll i = 0; i < N; ++i) {
        cin >> temp;
        tempPair.first = temp;
        cin >> temp;
        tempPair.second = temp;
        bebek.push_back(tempPair);
    }

    sort(bebek.begin(), bebek.end());

    for (ll i = 0; i < N; ++i) {
        if (D - bebek[i].first >= 0) {
            while (D - bebek[i].first >= 0 && bebek[i].second != 0) {
                D -= bebek[i].first;
                bebek[i].second -= 1;
                bebekSenang += 1;
            }
        } else {
            break;
        }
    }

    cout << bebekSenang;
}

