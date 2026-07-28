#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>

using namespace std;
using ll = int64_t;

int main() {
    ll size, score, best = 0;
    int charIndex = 0;
    string item;
    vector<string> target = {"OSN", "ONS", "NOS", "NSO", "SNO", "SON"};

    cin >> size >> item;
    
    for (ll i = 0; i < target.size(); ++i) {
        charIndex = 0;
        score = 0;
        for (ll j = 0; j < size; ++j) {
            if (item[j] == target[i][charIndex]) {
                if (charIndex == 2) {
                    ++score;
                }
                charIndex = (charIndex+1)%3;
            }
        }

        if (score > best) {
            best = score;
        }
    }
    
    cout << best;
}
