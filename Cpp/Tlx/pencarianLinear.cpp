#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int target, size, item, best;

    cin >> size >> target;
    cin >> best;

    for (int i = 0; i < size-1; ++i) {
        cin >> item;
        if (abs(target-item) <= abs(target-best)) {
            if (abs(target-item) == abs(target-best)) {
                if (item < best) {
                    best = item;
                }
            } else {
                best = item;
            }
        }
    }

    cout << best;
}
