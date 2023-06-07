/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    using iter = vector<int>::const_iterator;
    TreeNode *solve(iter pre_begin, iter pre_end, iter in_begin, iter in_end) {
        if (distance(pre_begin, pre_end) < 1)
            return nullptr;
        auto root = find(in_begin, in_end, *pre_begin);
        auto left_len = distance(in_begin, root);
        return new TreeNode{
            *pre_begin,
            solve(pre_begin + 1, pre_begin + 1 + left_len, in_begin, in_begin + left_len),
            solve(pre_begin + 1 + left_len, pre_end, in_begin + left_len + 1, in_end)
        };
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
// @lc code=end

