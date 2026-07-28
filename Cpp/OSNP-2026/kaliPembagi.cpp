#include <iostream>
#include <stdint.h>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = int64_t;

// WE LOVE SPAGHETTI CODE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

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

unordered_map<ll, ll> primeFactorization(ll n, vector<ll> primes) {
    ll size = primes.size();
    unordered_map<ll, ll> result;

    for (int i = 0; i < size; ++i) {
        while (n % primes[i] == 0) {
            n /= primes[i];
            result[primes[i]] += 1;
        }
    }

    return result;
}

bool isValid(unordered_map<ll, ll> start, unordered_map<ll, ll> end) {
    for (auto i : start) { if (end[i.first] < i.second) { return false; } }
    for (auto i : end) { if (start[i.first] == 0) { return false; } }
    return true;
}

unordered_map<ll, ll> primeDifferences(unordered_map<ll, ll> startFactors, unordered_map<ll, ll> endFactors) {
    unordered_map<ll, ll> result;
    for (auto i : endFactors) {
        if (startFactors[i.first] != i.second) {
            result[i.first] = i.second-startFactors[i.first];
        }
    }

    return result;
}

ll optimalMultiplier(ll start, ll end, unordered_map<ll, ll> &diff) {
    ll multiplier = 1;
    for (auto i : diff) {
        cout << i.first << " X " << i.second << endl;
        while (start%i.first == 0 && i.second != 0 && start % multiplier) {
            multiplier *= i.first;
            start *= i.first;
            diff[i.first] -= 1;
        }
    }
    return multiplier;
}


int main() {
    ll start, end, temp;
    vector<ll> primes;
    unordered_map<ll, ll> startFactors, endFactors, diff;

    cin >> start >> end;

    primes = primeSieve(end);

    startFactors = primeFactorization(start, primes);
    endFactors = primeFactorization(end, primes);
    
    cout << "PRIMES: \n";
    for (auto i : primes) {
        cout << i << endl;
    }
    cout << endl << "FIRST: \n";
    for (auto i : startFactors) {
        cout << i.first << ' ' << i.second << endl;
    }
    cout << endl << "SECOND : \n";
    for (auto i : endFactors) {
        cout << i.first << ' ' << i.second << endl;
    }

    if (!isValid(startFactors, endFactors)) {
        cout << -1;
        return 0;
    }

    diff = primeDifferences(startFactors, endFactors);

    while (start != end) {
        temp = optimalMultiplier(start, end, diff);
        cout << temp << ' ' << start << endl;
        start *= temp;
    }
    /*
    while (start != end) {
    }
    */

}


