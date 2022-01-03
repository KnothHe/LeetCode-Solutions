/*
 * @lc app=leetcode id=82 lang=java
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (41.80%)
 * Likes:    4146
 * Dislikes: 142
 * Total Accepted:    399.6K
 * Total Submissions: 956.1K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;
        ListNode pre = null;
        while (cur != null) {
            ListNode dup = detectDuplicate(cur);
            // no duplicate
            if (dup == null) {
                pre = cur;
                cur = cur.next;
                continue;
            }

            ListNode next = dup.next;
            // head is duplicate
            if (pre == null) {
                head = next;
                cur = next;
                continue;
            }

            // head is not duplicate
            pre.next = next;
            cur = next;
        }

        return head;
    }

    public ListNode detectDuplicate(ListNode cur) {
        ListNode head = cur;
        if (head == null || head.next == null || head.val != head.next.val) {
            return null;
        }

        while (head.next != null && head.next.val == head.val) {
            head = head.next;
        }
        return head;
    }
}
// @lc code=end

