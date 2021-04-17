//445. Add Two Numbers II
//https://leetcode.com/problems/add-two-numbers-ii/
//https://youtu.be/LBVsXSMOIk4

class Solution {
public:
    ListNode* reverseList(ListNode* l){
        ListNode* prev=NULL;
        
        while(l){
            ListNode* temp = l->next;
            l->next=prev;
            prev = l;
            l=temp;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1=reverseList(l1);            
        ListNode* r2=reverseList(l2);
        ListNode * dummy = new ListNode();
        ListNode * temp = dummy;
        int carry=0;
        while(r1!=NULL || r2!=NULL || carry){
            int sum=0;
            if(r1!=NULL){
                sum+=r1->val;
                r1=r1->next;
            }
            if(r2!=NULL){
                sum+=r2->val;
                r2=r2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *node = new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return reverseList(dummy->next);
    }
};
