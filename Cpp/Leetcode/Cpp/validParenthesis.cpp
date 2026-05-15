// Note: I did not know how to solve this, so I did take the answer from leetcode.
class Solution {
public:
    bool isValid(string s) {
      stack<char> stack = {};

      for (char bracket : s) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
          stack.push(bracket);
        } else {
          if (stack.empty()) {
            return false;
          }
          char top = stack.top();
          stack.pop();
          if (top == '(' && bracket != ')') return false;
          if (top == '{' && bracket != '}') return false;
          if (top == '[' && bracket != ']') return false;
        }
      }
      
      return stack.empty();
    }
};

