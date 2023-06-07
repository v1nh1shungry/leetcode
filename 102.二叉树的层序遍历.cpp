/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        vector<int> temp;
        int current = 0;
        queue<pair<TreeNode *, size_t>> q;
        q.push({root, current});
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            if (node == nullptr)
                continue;
            if (level != current) {
                res.push_back(std::move(temp));
                temp.clear();
                current = level;
            }
            temp.push_back(node->val);
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        res.push_back(std::move(temp));
        return res;
    }
};
// @lc code=end

