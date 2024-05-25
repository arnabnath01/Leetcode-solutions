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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root); 
        bool flag=true;
        while(!q.empty())
        {
            vector<int>levels;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* tmp=q.front();
                q.pop();

                    if(tmp->left!=nullptr) q.push(tmp->left);
                if(tmp->right!=nullptr) q.push(tmp->right); 
                 levels.push_back(tmp->val);
                //  flag=!flag;
            }

            if(flag){
               
                 ans.push_back(levels);
                flag=!flag;
            }
            else{
                 reverse(levels.begin(),levels.end());
                ans.push_back(levels);
                flag=!flag;
            }
            
        }
        return ans;
    }
};