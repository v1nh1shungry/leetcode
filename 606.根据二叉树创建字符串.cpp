/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode* root) {
        string ans;
        ans += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
            return ans;
        if (root->left) {
            ans.push_back('(');
            ans += tree2str(root->left);
            ans.push_back(')');
        }
        else
            ans += "()";
        if (root->right) { 
            ans.push_back('(');
            ans += tree2str(root->right);
            ans.push_back(')');
        }
        return ans;
    }
};
// @lc code=end

