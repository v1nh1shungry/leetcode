/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        bool carry = false;
        auto ia = a.begin(), ib = b.begin();
        while (ia != a.end() && ib != b.end()) {
            int sum = carry + (*ia - '0') + (*ib - '0');
            carry = sum > 1;
            res.push_back('0' + sum % 2);
            ++ia;
            ++ib;
        }
        while (ia != a.end()) {
            int sum = carry + (*ia - '0');
            carry = sum > 1;
            res.push_back('0' + sum % 2);
            ++ia;
        }
        while (ib != b.end()) {
            int sum = carry + (*ib - '0');
            carry = sum > 1;
            res.push_back('0' + sum % 2);
            ++ib;
        }
        if (carry)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

