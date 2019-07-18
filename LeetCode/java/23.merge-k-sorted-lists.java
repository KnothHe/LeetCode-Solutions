/*
 * @lc app=leetcode id=23 lang=java
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (34.21%)
 * Total Accepted:    413.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;
        ListNode node = new ListNode(0);
        ListNode head = node;
        int min = 0;
        while (true) {
            for (int i = 0; i < lists.length; i++) {
                if (lists[i] != null && 
                        (lists[min] == null || lists[i].val < lists[min].val)) {
                    min = i;
                }
            }
            if (lists[min] == null) break;
            node.next = new ListNode(lists[min].val);
            node = node.next;
            lists[min] = lists[min].next;
        }
        return head.next;
    }
}
