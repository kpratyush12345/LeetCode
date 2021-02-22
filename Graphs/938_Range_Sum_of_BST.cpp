//938. Range Sum of BST
//https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root == NULL)
		    return 0;
        
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }    
        return  sum + rangeSumBST(root->right,low,high) + rangeSumBST(root->left,low,high);
    }
};
