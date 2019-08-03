/*This is a function problem.You only need to complete the function given below*/
/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL) return NULL;
    
    if(root->data<n1 && root->data <n2)
        return LCA(root->right,n1,n2);
        
    if(root->data > n1 && root->data > n2)
        return LCA(root->left,n1,n2);
 
    return root;
}
