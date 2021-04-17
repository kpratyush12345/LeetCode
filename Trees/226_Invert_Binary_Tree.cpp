//226. Invert Binary Tree
//https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    void swap(TreeNode *curr){
        if(!curr) return;
        
        TreeNode *temp;
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        
        swap(curr->left);
        swap(curr->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};
