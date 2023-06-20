/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto is = s.begin(), it = t.begin();
        while (is != s.end() && it != t.end()) {
            if (*is == *it)
                ++is;
            ++it;
        }
        return is == s.end();
    }
};
// @lc code=end

