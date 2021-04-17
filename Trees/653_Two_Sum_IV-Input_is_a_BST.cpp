//653. Two Sum IV - Input is a BST
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
public:
    set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return 0;
        if(s.find(root->val)!=s.end()) return 1;
        else s.insert(k-(root->val));
        
    return findTarget(root->left,k) || findTarget(root->right,k);  
   }
};
