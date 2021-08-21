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
    void aux(TreeNode* node, int target, vector<vector<int>>& vec, vector<int>& path){
        path.push_back(node->val);
        if(node->val == target && !node->left && !node->right){
            vec.push_back(path);
        }
        if(node->left){
            aux(node->left, target-node->val, vec, path);
        }
        if(node->right){
            aux(node->right, target-node->val, vec, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return vector<vector<int>>();
        vector<vector<int>> result;
        vector<int> path;
        aux(root, targetSum, result, path);
        return result;
    }
};