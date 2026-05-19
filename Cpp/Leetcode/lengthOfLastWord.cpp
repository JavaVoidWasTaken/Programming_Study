class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int index = s.size()-1;
        while (s[index] == ' ') {
          --index;
          if (index <= 0) {
            break;
          }
        }
        while (s[index] != ' ') {
          ++length;
          --index;
          if (index < 0) {
            break;
          }
        }
        return length;
    }
};
