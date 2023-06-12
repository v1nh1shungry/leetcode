/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *solve(iter begin, iter end) {
        auto len = distance(begin, end);
        if (len == 0)
            return nullptr;
        auto mid = begin + len / 2;
        return new TreeNode{
            *mid,
            solve(begin, mid),
            solve(mid + 1, end)
        };
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums.begin(), nums.end());
    }
};
// @lc code=end

