#include <iostream>
#include <vector>
using namespace std;

bool agakPrima(int x) {
    int factors = 0;
    for (int i = 1; i <= x; ++i) {
        if (x % i == 0) {
            ++factors;
        }
        if (factors > 4) {
            return false;
        }
    }
    return true;
}

int main() {
    int size, temp;       
    vector<int> list;

    cin >> size;

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        list.push_back(temp);
    }
    
    for (int i = 0; i < size; ++i) {
        if (agakPrima(list[i])) {
            cout << "YA\n";
        } else {
            cout << "TIDAK\n";
        }
    }
}

