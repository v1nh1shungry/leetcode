/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dump;
        dump.next = head;
        auto *p = head;
        while (p->next) {
            auto *t = &dump;
            while (t != p && t->next->val <= p->next->val)
                t = t->next;
            if (t != p) {
                auto *next = p->next->next;
                p->next->next = t->next;
                t->next = p->next;
                p->next = next;
            } else {
                p = p->next;
            }
        }
        return dump.next;
    }
};
// @lc code=end

