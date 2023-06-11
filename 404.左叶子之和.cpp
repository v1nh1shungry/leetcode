/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (root == nullptr)
                continue;
            if (root->left) {
                if (root->left->left == nullptr && root->left->right == nullptr)
                    ans += root->left->val;
                else
                    q.push(root->left);
            }
            q.push(root->right);
        }
        return ans;
    }
};
// @lc code=end

