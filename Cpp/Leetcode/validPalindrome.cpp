class Solution {
public:
	bool isPalindrome(string s) {
		string sanitized = "";
		for (int i = 0; i < s.size(); ++i) {
		    if (s[i] >= 'a' && s[i] <= 'z') {
			sanitized += s[i];
		    } else if (s[i] >= 'A' && s[i] <= 'Z') {
			sanitized += s[i]+32;
		    }
		}
		cout << sanitized;

		for (int i = 0; i < s.size()/2; ++i) {
		    if (sanitized[i] != sanitized[sanitized.size()-i-1]) {
			return false;
		    }
		}
		return true;
	}
};

