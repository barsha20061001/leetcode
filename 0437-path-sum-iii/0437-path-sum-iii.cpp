class Solution {
public:
    unordered_map<long long, int> prefixCount;
    int paths = 0;

    void dfs(TreeNode* root, long long currentSum, int targetSum) {
        if (root == nullptr)
            return;

        currentSum += root->val;

        // A previous prefix sum of currentSum - targetSum
        // forms a downward path whose sum equals targetSum.
        paths += prefixCount[currentSum - targetSum];

        prefixCount[currentSum]++;

        dfs(root->left, currentSum, targetSum);
        dfs(root->right, currentSum, targetSum);

        // Remove this node's prefix sum while backtracking.
        prefixCount[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefixCount[0] = 1;
        dfs(root, 0, targetSum);
        return paths;
    }
};