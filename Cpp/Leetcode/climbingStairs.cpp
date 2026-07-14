class Solution {
public:
    int climbStairs(int n) {
      int a = 0;
      int b = 0;
      int c = 1;
      for (int i = 0; i < n; ++i) {
        b = c;
        c = a+b;
        a = b;
      }
      return c;
    }
};

// 0 1 1 2 3 
