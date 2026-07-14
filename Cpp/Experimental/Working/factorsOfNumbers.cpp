#include <iostream>
#include <string>
using namespace std;

int main() {
    int size;
    int counter;
    bool odd;
    string answer;
    
    cin >> size;

    for (int i = 0; i < size; ++i) {
        counter = 1;
        odd = true;
        answer = "Iteration " + to_string(i) + " : ";
        for (int j = 0; j <= i; ++j) {
            if (i % counter == 0) {
                answer += to_string(counter) + ' ';
                odd = !odd;
            }
            ++counter;
        }
        if (odd) {
            cout << "Odd  ";
        } else {
            cout << "Even ";
        }
        cout << answer << endl;
    }

    return 0;
}


