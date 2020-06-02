// https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

bool solve(Node* root,int sum,int& mx){
    if(!root){
        return sum==mx;
    }
    int l = solve(root->left,sum+root->data,mx);
    int r = solve(root->right,sum+root->data,mx);
    if(l || r){
        return true;
    }else{
        return false;
    }
}

bool hasPathSum(Node *root, int sum) {
    bool ans = solve(root,0,sum);
    return ans;
}


-----------------------------OR----------------------------

bool hasPathSum(Node *node, int sum) {
    if (node == NULL) 
        return sum == 0; 
    return hasPathSum(node->left, sum - node->data) ||  
           hasPathSum(node->right, sum - node->data); 
}
