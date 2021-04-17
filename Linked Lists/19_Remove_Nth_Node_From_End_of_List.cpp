//19. Remove Nth Node From End of List
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
                ListNode* temp=new ListNode();
        temp=head;
        int size=0;
        while(head!=0){
            size++;
            head=head->next;
        }
        if(size==1){
            temp=NULL;
            return temp;
        }
        head=temp;
        int s=size-n;
        if(s==0){
            temp=head->next;
            return temp;
        }
        int c=1;
        while(c!=s)
        {
            head=head->next;
            c++;
        }
        head->next=head->next->next;
        return temp;
    }
};
