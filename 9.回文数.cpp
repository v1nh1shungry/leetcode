/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        auto s = to_string(x);
        return std::equal(s.begin(), s.begin() + s.size(), s.rbegin());
    }
};
// @lc code=end

