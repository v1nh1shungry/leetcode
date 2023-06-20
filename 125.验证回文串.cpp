/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (char c : s)
            if (isalnum(c))
                t.push_back(tolower(c));
        return equal(t.begin(), t.begin() + t.size() / 2, t.rbegin());
    }
};
// @lc code=end

