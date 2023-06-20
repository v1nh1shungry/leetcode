/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int64_t a = 1, b = 2;
        for (int i = 0; i < n - 1; ++i) {
            b = a + b;
            a = b - a;
        }
        return static_cast<int>(a);
    }
};
// @lc code=end

