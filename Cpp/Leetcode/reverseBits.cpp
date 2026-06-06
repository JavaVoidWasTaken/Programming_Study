class Solution {
public:
    int reverseBits(int n) {
      int reverse = 0;
      int bit = 0;

      for (int i = 0; i < 32; ++i) {
        bit = n & 1;
        n >>= 1;
        cout << bit << ' ';
        reverse <<= 1;
        reverse |= bit;
      }

      return reverse;
    }
};
