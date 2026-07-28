#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Finds the first index that is lower than or equal to the target in the list.
// Returns a -1 if no item can be found.
// e.g. (2, 1 2 3 4 5) = 1
// e.g. (3, 3,3,3,4,5) = 0

int lowBinary(int target, vector<int> list) {
    int left = 0;
    int right = list.size()-1;

    while (left <= right) {
        int middle = (left+right)/2;
        cout << middle << ' ';
        if (list[middle] <= target) {
            if (middle == 0) {
                return middle;
            } else if (list[middle-1] <= target) {
                right = middle-1;
            } else if (middle != list.size()-1) {
                if (list[middle+1] <= target) {
                    left = middle+1;
                }
            } else {
                return middle;
            }
        } else if (list[middle] > target) {
            right = middle-1;
        }
    }

    return -1;
}


int main() {
    int size, questions, temp;
    int x, y;
    vector<int> bebek;

    cin >> size;

    for (int i = 0; i < size; ++i) {
        cin >> temp;
        bebek.push_back(temp);
    }
    
    cin >> questions;
      
    for (int i = 0; i < questions; ++i) {
        cin >> x;
        cout << lowBinary(x, bebek) << '\n';
    }
}
