/*G
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return solve(root, 0);
    }

    int solve(TreeNode* node, int depth) {
        if (node == nullptr) {
            return depth;
        } else {
            ++depth;
            return max(solve(node->left, depth), solve(node->right, depth));
        }
    }
};
