/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool solve(TreeNode *lhs, TreeNode *rhs) {
        if (lhs == nullptr && rhs == nullptr)
            return true;
        if (lhs == nullptr || rhs == nullptr)
            return false;
        return lhs->val == rhs->val && solve(lhs->left, rhs->right) && solve(lhs->right, rhs->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};
// @lc code=end

