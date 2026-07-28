#include <iostream>
#include <string>

using namespace std;

void fail() {
    cout << "Wah, tidak bisa :(";
}

void success() {
    cout << "Tentu saja bisa!";
}

int main() {
    string first, second, temp;

    cin >> first >> second;

    if ((first.size() <= second.size()) || (first.size()-second.size() > 1)) {
        fail();
        return 0;
    }

    for (int i = 0; i < first.size(); ++i) {
        temp = first;
        temp.erase(i, 1);
        if (temp == second) { success(); return 0; }
    }
    
    fail();
    return 0;
}

