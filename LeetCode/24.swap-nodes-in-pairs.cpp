/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (40.74%)
 * Total Accepted:    239.3K
 * Total Submissions: 586.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Note:
 * 
 * 
 * Your algorithm should use only constant extra space.
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fst = head;
        ListNode* snd = fst->next;
        fst->next = snd->next;
        snd->next = fst;
        ListNode* rtn = snd;
        snd = fst->next;
        if (snd) {
            ListNode* thd = snd->next;
            while (fst && snd && thd) {
                snd->next = thd->next;
                thd->next = snd;
                fst->next = thd;
                fst = snd;
                snd = snd->next;
                if (snd) {
                    thd = snd->next;
                } else {
                    thd = nullptr;
                }
            }
        }
        return rtn;
    }
};
