class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle = {{1}, {1, 1}};
        vector<int> temp = {};

        if (numRows == 1) {
          return {{1}};
        } else if (numRows == 2) {
          return {{1}, {1, 1}};
        }

        for (int i = 2; i < numRows; ++i) {
          for (int j = 0; j <= i; ++j) {
            if (j-1 < 0 || j >= i) {
              temp.push_back(1);
            } else {
              temp.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
            }
          }
          triangle.push_back(temp);
          temp = {};
        }

        return triangle;
    }
};
