#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, B, temp;
  vector<int> list = {};
  cin >> N >> B;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    list.push_back(temp);
  }

  sort(list.begin(), list.end());

  int64_t currentHeight = 0;
  int64_t count = 0;
  for (int i = N-1; i >= 0; --i) {
    if (currentHeight >= B) {
      break;
    }
    currentHeight += list[i];
    ++count;
  }
  
  cout << count;
}
