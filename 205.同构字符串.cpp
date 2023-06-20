/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < s.size(); ++i) {
            char x = s[i], y = t[i];
            if (auto it = s2t.find(x); it != s2t.end() && it->second != y)
                return false;
            if (auto it = t2s.find(y); it != t2s.end() && it->second != x)
                return false;
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};
// @lc code=end

