class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int vectSize = strs.size();
    int strSize = strs[0].size();
    
    for (int i = 0; i < strSize; ++i) {
      for (int j = 0; j < vectSize-1; ++j) {
        if (strs[j][i] != strs[j+1][i]) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};
