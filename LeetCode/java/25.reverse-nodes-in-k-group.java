/*
 * @lc app=leetcode id=25 lang=java
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (36.22%)
 * Total Accepted:    195.7K
 * Total Submissions: 525.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 *
 * Reference:
 *  https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11423/Short-but-recursive-Java-code-with-comments
 *
 * 1.
 *
 * head   (next)    cur
 * |        |        |
 * v        v        v
 * 1   ->   2   ->   3   ->   4   ->   5
 *
 * 2.
 *
 * head    cur     (next)
 * |        |        |
 * v        v        v
 * 2        1   ->   3   ->   4   ->   5
 * |                 ^
 * |                 |
 * |_________________|
 *
 * 3.
 *
 * cur              head
 * |                 |
 * v                 v  
 * 2   ->   1   ->   3   ->   4   ->   5
 *                   ^
 *                   |
 *                  next
 *
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        int count = 0;
        ListNode cur = head;
        while ( cur != null && count < k ) {
            cur = cur.next;
            count++;
        }
        // have k nodes
        if ( count == k ) {
            cur = reverseKGroup(cur, k); // get head of next part after reversing
            while (count-- > 0) { // repeat count times
                ListNode next = head.next; // save next node of head
                head.next = cur; // next node of head is cur
                cur = head; // cur become head
                head = next // head become next
            }
            head = cur // return value is head of current part
        }
        return head;
    }
}
