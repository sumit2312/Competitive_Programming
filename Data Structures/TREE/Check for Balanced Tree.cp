// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1


int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}


void solve(Node* root,bool& res){
    if(root == NULL){
        return ;
    }
    solve(root->left,res);
    solve(root->right,res);
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)>1){
        res = false;
    }
    
}

bool isBalanced(Node *root)
{
    bool res = true;
    solve(root,res);
    return res;
}
