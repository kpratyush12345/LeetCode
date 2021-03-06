//328. Odd Even Linked List
//https://leetcode.com/problems/odd-even-linked-list/
//https://youtu.be/ErkOfemuEuc

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode * odd = head;
        ListNode * even = head->next;
        ListNode * evenHead = even;
        while(odd->next != NULL && even->next!=NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
