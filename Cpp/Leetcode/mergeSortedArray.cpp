class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = n-1; i >= 0; --i) {
          int left = 0;
          int right = m-1;
          while (left <= right) {
            int middle = (left+middle)/2;
            if (nums1[middle] == nums2[i]) {
              cout << nums1[middle];
            } else if (nums1[middle] < nums2[i]) {
              left = middle+1;
            } else {
              right = middle-1;
            }
          }
        }
    }
};
