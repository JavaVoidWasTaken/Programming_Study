#include <iostream>
#include <stdint.h>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = int64_t;

vector<ll> primeSieve(ll n) {
    vector<bool> sieve(n, true);
    vector<ll> result;

    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i < n; ++i) {
        if (sieve[i]) {
            result.push_back(i);
            for (int j = i; j < n; j += i) { sieve[j] = false; }
        }
    }

    return result;
}

unoredered_map<ll, ll> primeFactorization(ll n, vector<ll> primes) {
    ll size = primes.size();
    unoredered_map<ll, ll> result;

    for (int i = 0; i < size; ++i) {
        if (n % primes[i] == 0) { 
            while (n % primes[i] == 0) {
                n /= primes[i];
                result[i] += 1;
            }
        }
    }

    return result;
}

unordered_map<ll, ll> primeDifferences(unordered_map<ll,ll> startFactors, unordered_map<ll,ll> endFactors) {
    ll size = startFactors.size();
    vector<ll> result;
    ll i = 0, j = 0; // i = start, j = end.
    while (true) {
        if (startFactors[i] != endFactors[j]) {
            result.push_back(endFactors[j]);
        }
        ++i;
        ++j;
    }
}

ll optimalMultiplier(ll start, ll end, vector<ll> primes) {}


int main() {
    ll start, end;
    vector<ll> primes;
    unordered_map<ll, ll> startFactors, endFactors;

    cin >> start >> end;

    primes = primeSieve(end);

    startFactors = primeFactorization(start, primes);
    endFactors = primeFactorization(end, primes);

    for (auto i : startFactors) {
        cout << i << ' ';
    }
    cout << endl;
    for (auto i : endFactors) {
        cout << i << ' ';
    }

}


