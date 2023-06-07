/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dump;
        dump.next = head;
        ListNode *p1 = &dump, *p2 = head;
        for (int i = 0; i < n; ++i)
            p2 = p2->next;
        while (p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return dump.next;
    }
};
// @lc code=end

