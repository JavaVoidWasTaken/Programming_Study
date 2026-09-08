class Solution {
public:
    int strStr(string haystack, string needle) {
        int start = 0;
        int j = 0;
        int size = haystack.size();
        int target = needle.size();

        for (int i = 0; i < size; ++i) {
            cout << haystack[i] << ' ' << needle[j] << endl;
            if (haystack[i] == needle[j]) {
                if (j == 0) start = i;
                ++j;
                if (j == target) return start;
            } else { 
                i = ++start-1;
                j = 0;
            }
        }
        return -1;
    }
};
