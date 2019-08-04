/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// A wrapper over leftViewUtil()

void leftView(Node* root,int level,int *mx_level){
    if(root == NULL) return;
    
    if(level>*mx_level){
        cout<<root->data<<" ";
        *mx_level = level;
    }
    
    if(root->left) leftView(root->left,level+1,mx_level);
    if(root->right) leftView(root->right,level+1,mx_level);
}

void leftView(Node *root)
{
    int mx_level=0;
    leftView(root,1,&mx_level);
}
