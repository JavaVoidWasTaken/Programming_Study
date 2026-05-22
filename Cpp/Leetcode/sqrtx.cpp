class Solution {
public:
    int mySqrt(int x) {
        long mult = 1;
        while (mult*mult*2 < x) {
          mult *= 2;
        }
        while (mult*mult < x) {
          mult += 1;
        }
        while (mult*mult > x) {
          mult -= 1;
        }
        return (int)mult;
    }
};
