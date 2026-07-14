#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size, temp;
    int maskSize = 990001;
    vector<bool> primeMask(maskSize, true);
    vector<int> primes;

    cin >> size;

    // Pre-generate primes
    for (int i = 2; i < maskSize; ++i) {
        if (primeMask[i]) {
            primes.push_back(i);
            for (int j = i; j < maskSize; j += i) {
                primeMask[j] = false;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        cout << primes[temp-1] << '\n';
    }
}
