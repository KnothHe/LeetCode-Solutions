#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *rtn = new ListNode(0), *rtnNode = rtn;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            if (l1 != NULL) {
                carry += l1->val;
                l1 = l1->next;    
            }
            if (l2 != NULL) {
                carry += l2->val;
                l2 = l2->next;    
            }
            rtnNode->next = new ListNode(carry % 10);
            rtnNode = rtnNode->next;
            carry /= 10;
        }
        return rtn->next;
    }
};

int main()
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution* solution = new Solution();
    ListNode* result = solution->addTwoNumbers(l1, l2);
    ListNode* resNode = result;
    while (resNode != NULL) {
        cout << resNode->val << endl;
        resNode = resNode->next;
    }
}
