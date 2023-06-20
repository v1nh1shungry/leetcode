/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        auto it = find_if(s.begin(), s.end(), [](char c) { return !isspace(c); });
        int res = 0;
        while (it != s.end()) {
            res += 1;
            auto temp = find_if(it, s.end(), [](char c) { return isspace(c); });
            it = find_if(temp, s.end(), [](char c) { return !isspace(c); });
        }
        return res;
    }
};
// @lc code=end

