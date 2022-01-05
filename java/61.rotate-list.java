/*
 * @lc app=leetcode id=61 lang=java
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (33.33%)
 * Likes:    3673
 * Dislikes: 1220
 * Total Accepted:    461.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, rotate the list to the right by k
 * places.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }

        // 计算 len 和 end
        int len = 1;
        ListNode end = head;
        while (end.next != null) {
            len++;
            end = end.next;
        }

        // 预处理 k
        k = k % len;

        // 不需要翻转
        if (k == 0) return head;

        // 计算出需要新的 head, headPre 和 headNext
        int nk = len - k + 1;
        int nkp = nk - 1;
        ListNode newHeadPre = head;
        ListNode newHead = newHeadPre.next;
        for (int i = 0; i < nkp - 1; i++) {
            newHeadPre = newHeadPre.next;
            newHead = newHead.next;
        }

        // 翻转
        newHeadPre.next = null;
        end.next = head;
        return newHead;
    }
}
// @lc code=end

