//23. Merge k Sorted Lists
//https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.size() == 0){
            ListNode* a=NULL;
            return a;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        int c=0;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* l1 = new ListNode();
            l1=lists[i];
            if(l1==0)
            {
                c++;
                continue;
            }
            while(l1!=0)
            {
                pq.push(l1->val);
                l1=l1->next;
            }
        }
        if(c == lists.size()){
            ListNode* b = NULL;
            return b;
        }
        ListNode* res = new ListNode();
        ListNode* first = new ListNode();
        first = res;
        res->val = pq.top();
        pq.pop();
        while(!pq.empty()){
            ListNode* tmp = new ListNode();
            tmp->val = pq.top();
            pq.pop();
            res->next = tmp;
            res = res->next;
        }
        return first;
    }
};
