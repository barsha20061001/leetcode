/**
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
    int ans = 0;

    void dfs(TreeNode* node, int leftLen, int rightLen) {
        if (node == nullptr) return;

        ans = max(ans, max(leftLen, rightLen));

        // Moving left continues a path whose previous move was right.
        dfs(node->left, rightLen + 1, 0);

        // Moving right continues a path whose previous move was left.
        dfs(node->right, 0, leftLen + 1);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }
};