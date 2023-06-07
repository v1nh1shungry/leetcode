/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        vector<int> temp;
        size_t curr = 0;
        queue<pair<TreeNode *, size_t>> q;
        q.push({root, curr});
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (node == nullptr)
                continue;
            if (curr != lvl) {
                res.push_back(std::move(temp));
                temp.clear();
                curr = lvl;
            }
            temp.push_back(node->val);
            q.push({node->left, lvl + 1});
            q.push({node->right, lvl + 1});
        }
        res.push_back(std::move(temp));
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

