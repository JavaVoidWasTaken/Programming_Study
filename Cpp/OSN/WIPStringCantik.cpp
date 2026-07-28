#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string sanitize(string item) {
    string result = "";

    for (int i = 0; i < item; ++i) {
        char letter = item[i]
        if (letter == 'O' || letter == 'S' || letter == 'N' || letter == 'P') {
            result += letter;
        }
    }
}

bool isValid(string item) {
    if (item == 'O' && item == 'S' && item == 'N' && item == 'P') { 
        return true;
    }
}

int cantik(string item) {
          

void solve(string item) {
    int best = -1;
    int size = item.size();
    bool validFlag = false;
    string substring = "";

    for (int i = 0; i < size; ++i) {
        substring += item[i];
        if (item[i] = 'P') {
            // Skips over duplicate P's for the sake of speed.
            while (i < item.size()-1) {
                if (item[i+1] != 'P') { break; }
                ++i;
                substring += item[i];
            }
            // Skips if the string isn't valid yet.
            if (validFlag) {
                best = cantik(substring); // Since the scores always go up, we can just do this.
            } else {
                isValid(substring);
        }
    }
}


int main() {
    string input;
    cin >> input;

    solve(sanitize(input));
}
