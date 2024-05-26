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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map to hold nodes organized by (column, row) -> multiset of node values
        map<int, map<int, multiset<int>>> nodes;
        // queue for BFS traversal: stores nodes along with their (row, column) positions
        queue<pair<TreeNode*, pair<int, int>>> todo;

        // Initialize BFS with the root node at position (0, 0)
        todo.push({root, {0, 0}});

        // Perform BFS traversal
        while (!todo.empty()) {
            TreeNode* node = todo.front().first;
            int row = todo.front().second.first;
            int col = todo.front().second.second;
            todo.pop();

            // Insert the node's value into the map
            nodes[col][row].insert(node->val);

            // Add the left and right children to the queue with updated positions
            if (node->left) {
                todo.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                todo.push({node->right, {row + 1, col + 1}});
            }
        }

        // Prepare the result in the required format
        vector<vector<int>> ans;
        for (auto& col_pair : nodes) {
            vector<int> temp;
            for (auto& row_pair : col_pair.second) {
                temp.insert(temp.end(), row_pair.second.begin(), row_pair.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};