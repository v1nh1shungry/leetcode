/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode *, size_t>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            if (node == nullptr)
                continue;
            if (node->left == nullptr && node->right == nullptr)
                return level;
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        return 0;
    }
};
// @lc code=end

