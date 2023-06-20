/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        auto f = [](int l, int r) {
            return l == r ? to_string(l) : to_string(l) + "->" + to_string(r);
        };
        int i = 0, j = 1;
        vector<string> res;
        while (j < nums.size()) {
            if (nums[j] != nums[j - 1] + 1) {
                res.push_back(f(nums[i], nums[j - 1]));
                i = j;
            }
            j += 1;
        }
        res.push_back(f(nums[i], nums[j - 1]));
        return res;
    }
};
// @lc code=end

