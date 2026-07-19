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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1, ans = 1; //Stores the maximum sum found so far.
        //Initialized with root’s value (level 1 sum).
        long long maxSum = root->val;

        while (!q.empty()) { //Runs BFS until all nodes are processed.
            int sz = q.size(); //Stores how many nodes are present at the current level.
            long long sum = 0; //Stores the sum of node values at this level.

            for (int i = 0; i < sz; i++) { //Processes all nodes of the current level.
                TreeNode* cur = q.front(); //Gets the front node from the queue
                q.pop(); //Removes it from the queue

                sum += cur->val; //Adds the node’s value to the current level sum.

                if (cur->left) q.push(cur->left); //If left child exists, push it into the queue ; → it will be processed in the next level.
                if (cur->right) q.push(cur->right);
            }

            if (sum > maxSum) { //Checks if the current level sum is greater than previous maximum.
                maxSum = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};