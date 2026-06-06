class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int uniqueS = 0;
      int uniqueT = 0;
      string diffS = "";
      string diffT = "";
      unordered_map<char, int> mapS;
      unordered_map<char, int> mapT;

      for (int i = 0; i < s.size(); ++i) {
        if (!mapS.contains(s[i])) {
          mapS[s[i]] = uniqueS;
          ++uniqueS;
        }
        if (!mapT.contains(t[i])) {
          mapT[t[i]] = uniqueT;
          ++uniqueT;
        }
        diffS += mapS[s[i]];
        diffT += mapT[t[i]];
      }

      if (diffS == diffT) {
        return true;
      }
      return false;
    }
};
