class Solution {
public:
    void carryTens(vector<int>& input, int index) {
      if (input[index] == 10) {
        input[index] = 0;
        if (index == 0) {
          input.insert(input.begin(), 1);
        } else {
          input[index-1] += 1;
          carryTens(input, index-1);
        }
      }
    }

    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1] += 1;
        carryTens(digits, digits.size()-1);
        return digits;
    }
};
