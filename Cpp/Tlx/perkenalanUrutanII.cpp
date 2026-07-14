#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int size;
    string temp;
    vector<string> emptyList = {};
    vector<vector<string>> lengthList;
    
    cin >> size;
    
    // Create an empty vector with 10 vectors for each string length;
    for (int i = 0; i < 10; ++i) {
        lengthList.push_back(emptyList);
    }

    // Assign each input to each length in the list
    for (int i = 0; i < size; ++i) {
        cin >> temp;
        lengthList[string(temp).length()-1].push_back(temp);
    }

    // Sort and output.
    for (int i = 0; i < 10; ++i) {
        sort(lengthList[i].begin(), lengthList[i].end());
        for (auto j : lengthList[i]) {
            cout << j << '\n';
        }
    }
}
