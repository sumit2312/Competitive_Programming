/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure  used in the program
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
/* Computes the diameter of binary tree with given root.  */

int height(struct Node* node){
    if(node == NULL) return 0;
    
    return 1+max(height(node->left),height(node->right));
}

int diameter(Node* node)
{
    if(node == NULL) return 0;
    
    int lh = height(node->left);
    int rh = height(node->right);
    
    int ld = diameter(node->left);
    int rd = diameter(node->right);
    
    return max(lh+rh+1,max(ld,rd));
    
    
}
