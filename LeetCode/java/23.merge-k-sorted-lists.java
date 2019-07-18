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
 *
 * Refernece:
 *  https://leetcode.com/problems/merge-k-sorted-lists/discuss/10528/A-java-solution-based-on-Priority-Queue
 *
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;
        PriorityQueue<ListNode> pq = new PriorityQueue<>(lists.length,
                new Comparator<ListNode>() {
                    @Override
                    public int compare(ListNode lhs, ListNode rhs) {
                        return lhs.val - rhs.val;
                    }
                });
        ListNode head = new ListNode(0);
        ListNode node = head;
        for (ListNode ld : lists) {
            if (ld != null) pq.add(ld);
        }
        while (!pq.isEmpty()) {
            node.next = pq.poll();
            node = node.next;
            if (node.next != null) pq.add(node.next);
        }
        return head.next;
    }
}
