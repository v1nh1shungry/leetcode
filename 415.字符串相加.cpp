/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        auto it1 = num1.rbegin(), end1 = num1.rend();
        auto it2 = num2.rbegin(), end2 = num2.rend();
        bool carry = false;
        string ans;
        while (it1 != end1 && it2 != end2) {
            int sum = *it1 - '0' + *it2 - '0' + carry;
            carry = sum >= 10;
            ans.push_back(sum % 10 + '0');
            ++it1; ++it2;
        }
        while (it1 != end1) {
            int sum = *it1 - '0' + carry;
            carry = sum >= 10;
            ans.push_back(sum % 10 + '0');
            ++it1;
        }
        while (it2 != end2) {
            int sum = *it2 - '0' + carry;
            carry = sum >= 10;
            ans.push_back(sum % 10 + '0');
            ++it2;
        }
        if (carry)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

