/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        right(root,1,res);
        return res;
    }
private:
    void right(TreeNode* root,int level,vector<int> &res){
        if(root == NULL) return ;
        
        if(level > res.size()){
            res.push_back(root->val);
        }
        right(root->right,level+1,res);
        right(root->left,level+1,res);
    }
    
};
