//98. Validate Binary Search Tree
//https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool is_bst(TreeNode* node, TreeNode* min, TreeNode* max) {
        if (node == nullptr) {
            return true;
        }
        
        if ((min && node->val <= min->val) || (max && node->val >= max->val)) {
            return false;
        }

        return is_bst(node->left, min, node) && is_bst(node->right, node, max);
    }

    bool isValidBST(TreeNode* root) {
        return is_bst(root, nullptr, nullptr);
    }
};
