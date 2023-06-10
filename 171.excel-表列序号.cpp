/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        return accumulate(columnTitle.begin(), columnTitle.end(), 0, [](int lhs, char rhs) { return lhs * 26 + (rhs - 'A' + 1); });
    }
};
// @lc code=end

