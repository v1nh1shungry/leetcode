/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        queue<pair<TreeNode *, size_t>> q;
        int curr = 0;
        int prev = root->val;
        q.push({root, curr});
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (node == nullptr)
                continue;
            if (curr != lvl) {
                res.push_back(prev);
                curr = lvl;
            }
            prev = node->val;
            q.push({node->left, lvl + 1});
            q.push({node->right, lvl + 1});
        }
        res.push_back(prev);
        return res;
    }
};
// @lc code=end

