//206. Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/
//https://youtu.be/iRtLEoL-r-g

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while(head!=NULL){
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head=next;
        }
        return newHead;
    }
};
