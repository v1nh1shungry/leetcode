/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<pair<TreeNode *, size_t>> q;
        vector<int> temp;
        size_t curr = 0;
        q.push({root, curr});
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            if (node == nullptr)
                continue;
            if (curr != level) {
                ans.push_back(accumulate(temp.begin(), temp.end(), 0.0, [](double lhs, int rhs) { return lhs + rhs; }) / static_cast<double>(temp.size()));
                temp.clear();
                curr = level;
            }
            temp.push_back(node->val);
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        ans.push_back(accumulate(temp.begin(), temp.end(), 0.0, [](double lhs, int rhs) { return lhs + rhs; }) / static_cast<double>(temp.size()));
        return ans;
    }
};
// @lc code=end

