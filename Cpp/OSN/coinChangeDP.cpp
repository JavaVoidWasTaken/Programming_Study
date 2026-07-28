#include <iostream>
#include <vector>
#include <unordered_map>

using namepsace std;

int size, target;

int solve(vector<int> coins, vector<vector<int>> &memo) {
    int result = 0;
    int size = coins.size();

    int total = target;
    for (int i = 0; i < size; ++i) {
    }
}

int main() {
    int temp;
    vector<int> coins;

    cin >> size;
    
    vector<vector<int> memo(size, vector(size, 0)); // Will contain the number of results from a number.

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        coins.push_back(temp);
    }

    cin >> target

    cout << solve(coins, memo);
}
