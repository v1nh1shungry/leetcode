/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        queue<pair<TreeNode *, string>> q;
        q.push({root, to_string(root->val)});
        while (!q.empty()) {
            auto [node, path] = std::move(q.front());
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
                ans.push_back(std::move(path));
            } else {
                if (node->left)
                    q.push({node->left, path + "->" + to_string(node->left->val)});
                if (node->right)
                    q.push({node->right, path + "->" + to_string(node->right->val)});
            }
        }
        return ans;
    }
};
// @lc code=end

