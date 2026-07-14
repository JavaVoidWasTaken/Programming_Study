#include <iostream>
#include <stdint.h>
#include <cstring>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int64_t size;
    cin >> size;

    vector<bool> sieve(size, true);

    auto startTime = high_resolution_clock::now();
    auto currentTime = high_resolution_clock::now();
    auto prevTime = high_resolution_clock::now();

    for (int64_t i = 2; i < size; ++i) {
        if (sieve[i] == true) {
            for (int64_t j = i; j < size; j += i) {
                sieve[j] = false;
            }
            cout << "Prime: " << i << ", time to calculate:" << duration_cast<nanoseconds>(high_resolution_clock::now()- prevTime).count() << "ns \n";
            prevTime = high_resolution_clock::now();
        }
    }

    cout << "Total runtime: " << duration_cast<nanoseconds>(high_resolution_clock::now() - startTime).count() << "ns\n";
}


