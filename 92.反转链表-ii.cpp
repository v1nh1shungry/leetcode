/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dump{0, head};
        auto *begin = &dump, *end = head;
        for (int i = 0; i < left - 1; ++i)
            begin = begin->next;
        for (int i = 0; i < right; ++i)
            end = end->next;
        auto *p1 = end, *p2 = begin->next;
        while (p2 != end) {
            auto *next = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = next;
        }
        begin->next = p1;
        return dump.next;
    }
};
// @lc code=end

