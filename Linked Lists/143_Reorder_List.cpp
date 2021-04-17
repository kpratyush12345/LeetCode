//143. Reorder List
//https://leetcode.com/problems/reorder-list/

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> v;

        while(head){
            v.push_back(head);
            head = head->next;
        }
        
        int i=0;
        int j = v.size()-1;
        vector<int> r;
        while(i<=j){
            r.push_back(i);
            if(j>i)
                r.push_back(j);
            i++;
            j--;
        }
        int k=0;
        while(k<r.size()-1){
            v[r[k]]->next = v[r[k+1]];
            k++;
        }
        v[r[r.size()-1]]->next = NULL;
    }
};
