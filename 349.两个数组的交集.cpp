/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s, t;
        for (int i : nums1)
            s.insert(i);
        vector<int> res;
        for (int i : nums2)
            if (s.count(i))
                t.insert(i);
        copy(t.begin(), t.end(), back_inserter(res));
        return res;
    }
};
// @lc code=end

