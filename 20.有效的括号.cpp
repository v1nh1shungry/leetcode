/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        stack<char> stk;
        for (char c : s) {
            switch (c) {
            case '(':
            case '[':
            case '{':
                stk.push(c);
                break;
            case ')':
            case ']':
            case '}':
                if (stk.empty() || stk.top() != map[c])
                    return false;
                stk.pop();
                break;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

