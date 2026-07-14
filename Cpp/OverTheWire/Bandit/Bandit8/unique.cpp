// Hooray spaggheti code!
#include <iostream>
#include <string>
using namespace std;

int main() {
  int size;
  string current = "";

  for (int i = 0; i < size-1; ++i) {
    string before = current;
    cin >> current;
    if (before != current) {
      before = current;
      cin >> current;
      if (before != current) {
        cout << before << endl;
      }
    }
  }
}
