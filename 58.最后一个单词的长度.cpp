/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        auto begin = find_if(s.rbegin(), s.rend(), [](char c) { return isalpha(c); });
        return distance(begin, find_if(begin, s.rend(), [](char c) { return isspace(c); }));
    }
};
// @lc code=end

