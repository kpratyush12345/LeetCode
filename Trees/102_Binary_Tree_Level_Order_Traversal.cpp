//102. Binary Tree Level Order Traversal
//https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
         vector<vector<int>> ret;
    void helper(TreeNode* root, int i){
        
        if(!root) return;
        
        if(i==ret.size()){
            ret.push_back({});
        }
        
        ret[i].push_back(root->val);
        
        if(root->left != nullptr){
            helper(root->left, i+1);
        }
        if(root->right != nullptr){
            helper(root->right, i+1);
        }
    
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return ret;

    }
};
