/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *solve(iter in_begin, iter in_end, iter post_begin, iter post_end) {
        if (distance(in_begin, in_end) < 1)
            return nullptr;
        auto temp = post_end;
        advance(temp, -1);
        auto left_len = distance(in_begin, find(in_begin, in_end, *temp));
        return new TreeNode{
            *temp,
            solve(in_begin, in_begin + left_len, post_begin, post_begin + left_len),
            solve(in_begin + left_len + 1, in_end, post_begin + left_len, temp)
        };
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
// @lc code=end

