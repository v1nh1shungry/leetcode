/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dump;
        ListNode *p = &dump;
        bool carry = false;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            p->next = new ListNode{sum % 10};
            carry = sum >= 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            p->next = new ListNode{sum % 10};
            carry = sum >= 10;
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            p->next = new ListNode{sum % 10};
            carry = sum >= 10;
            p = p->next;
            l2 = l2->next;
        }
        if (carry)
            p->next = new ListNode{1};
        return dump.next;
    }
};
// @lc code=end

