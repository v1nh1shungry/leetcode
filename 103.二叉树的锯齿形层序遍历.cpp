/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, size_t>> q;
        int curr = 0;
        bool rev = false;
        vector<int> temp;
        q.push({root, curr});
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            if (node == nullptr)
                continue;
            if (curr != level) {
                if (rev)
                    reverse(temp.begin(), temp.end());
                ans.push_back(std::move(temp));
                temp.clear();
                curr = level;
                rev = !rev;
            }
            temp.push_back(node->val);
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        if (!temp.empty()) {
            if (rev)
                reverse(temp.begin(), temp.end());
            ans.push_back(std::move(temp));
        }
        return ans;
    }
};
// @lc code=end

