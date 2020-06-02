// https://practice.geeksforgeeks.org/problems/sum-tree/1/

int solve(Node* root,bool& res){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    int temp = l+r;
    if(root->data != temp){
        res = false;
    }
    return root->data+l+r;
}


bool isSumTree(Node* root)
{
     bool res = true;
     solve(root,res);
     return res;
}
