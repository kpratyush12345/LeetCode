//104. Maximum Depth of Binary Tree
//https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==0) return 0;
        return 1 + max(maxDepth(root->right),maxDepth(root->left));
    }
};
