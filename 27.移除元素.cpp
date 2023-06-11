/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = remove(nums.begin(), nums.end(), val);
        return nums.size() - distance(it, nums.end());
    }
};
// @lc code=end

