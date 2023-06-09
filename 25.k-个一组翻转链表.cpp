/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dump{0, head};
        auto *p1 = &dump;
        while (true) {
            auto *p2 = p1;
            for (int i = 0; i < k && p2; ++i)
                p2 = p2->next;
            if (p2 == nullptr)
                break;
            ListNode *p3 = p2->next, *p4 = p1->next, *p5 = p1->next;
            while (p3 != p2) {
                auto *next = p4->next;
                p4->next = p3;
                p3 = p4;
                p4 = next;
            }
            p1->next = p2;
            p1 = p5;
        }
        return dump.next;
    }
};
// @lc code=end

