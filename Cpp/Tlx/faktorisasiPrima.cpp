#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> generatePrimes(int x) {
    vector<bool> mask(x, true);
    vector<int> output;
    
    for (int i = 2; i < x; ++i) {
        if (mask[i] == true) {
            output.push_back(i);
            for (int j = i; j < x; j += i) {
                mask[j] = false;
            }
        }
    }

    return output;
}

// Holy spaggheti code, this piece of code should not exist and yet it does...
void printResult (vector<int> x) {
    int current = x[0];
    int size = x.size();
    int counter = 0;
    vector<int> counts;

    x.push_back(0);

    for (int item : x) {
        if (current == item) {
            ++counter;
        } else {
            counts.push_back(counter);
            counter = 1;
            current = item;
        }
    }

    int index = 0;
    current = x[0];
    for (int item : counts) {
        if (current != x[index]) {
            current = x[index];
            cout << " x ";
        }
        if (item == 1) {
            cout << x[index];
        } else {
            cout << x[index] << '^' << item;
        }
        index += item;
    }
    cout << '\n';
}


int main() {
    int input;
    int size = 1000000;
    vector<int> primes = generatePrimes(size);
    vector<int> factors;

    cin >> input;

    for (int i = 0; i < size; ++i) {
        while (true) {
            if (input % primes[i] == 0 && input != 1) {
                input /= primes[i];
                factors.push_back(primes[i]);
            } else {
                break;
            }
        }
        if (input == 1) {
            break;
        }
    }

    cout << '\n';
    printResult(factors);
}
