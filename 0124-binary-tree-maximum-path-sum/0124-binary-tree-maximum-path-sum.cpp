/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int helper(TreeNode* root,int& maxi){
        if(!root) return 0;
        int l =max(0,helper(root->left,maxi));  // back tract left side
        int r = max(0,helper(root->right,maxi));
        maxi=max(maxi,root->val+l+r);
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};