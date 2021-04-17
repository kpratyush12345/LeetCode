//572. Subtree of Another Tree
//https://leetcode.com/problems/subtree-of-another-tree/

class Solution {
public:
    bool isIdentical(TreeNode* s, TreeNode* t)
    {
        if(s == NULL && t == NULL)  return true;
        if(s == NULL || t == NULL)  return false;  
        if(s->val==t->val && isIdentical(s->left, t->left) && isIdentical(s->right, t->right)) return true;
        return false;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL)    return true;
        if(s == NULL)  return false;
        if(t == NULL)  return true;
        
        if(isIdentical(s, t)) return true;
        
        return (isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};
