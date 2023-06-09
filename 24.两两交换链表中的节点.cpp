/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dump{0, head};
        auto *p = &dump;
        while (p->next && p->next->next) {
            auto *next = p->next;
            p->next = p->next->next;
            next->next = p->next->next;
            p->next->next = next;
            p = next;
        }
        return dump.next;
    }
};
// @lc code=end

