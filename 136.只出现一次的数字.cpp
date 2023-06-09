/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin() + 1, nums.end(), nums.front(), [](int lhs, int rhs) { return lhs ^ rhs; });
    }
};
// @lc code=end

