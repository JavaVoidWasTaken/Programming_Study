class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) {
        return false;
      }

      long long temp = x;
      long long reverse = 0;
      while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
      }

      if (reverse != x) {
        return false;
      } else {
        return true;
      }
    }
};
