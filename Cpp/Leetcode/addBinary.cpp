// P.s. I am writing this at midnight and I am sleepy so don't mind the spaggheti code.
class Solution {
public:
    void carryBinary(string& a, int index) {
      for (int i = index; i >= 0; --i) {
        if (a[i] >= '2') {
          a[i] -= 2;
          if (i == 0) {
            a.insert(a.begin(), '1');
          }
          else {
            a[i-1] += 1;
          }
        }
      }
    }

    string addBinary(string a, string b) {
      if (a.size() <= b.size()) {
        for (int i = a.size()-1; i >= 0; --i) {
          if (a[i] == '1'){
            b[b.size()-1-(a.size()-1-i)] += 1;
          }
        }
        for (int i = b.size()-1; i >= 0; --i) {
          carryBinary(b, i);
        }

        return b;
      }
      else {
        for (int i = b.size()-1; i >= 0; --i) {
          if (b[i] == '1'){
            a[a.size()-1-(b.size()-1-i)] += 1;
          }
        }
        for (int i = a.size()-1; i >= 0; --i) {
          carryBinary(a, i);
        }

        return a;
      }
    }
};
