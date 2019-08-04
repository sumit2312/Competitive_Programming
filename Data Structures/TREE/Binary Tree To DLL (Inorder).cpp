// Sol video - https://www.youtube.com/watch?v=FsxTX7-yhOw&list=PLeIMaH7i8JDj7DnmO7lll97P1yZjMCpgY&index=14
// Question  -  https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1/?track=md-tree&batchId=144
/* Structure for tree and linked list
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
// This function should convert a given Binary tree to Doubly
// Linked List
void bToDLL(Node *root, Node **head_ref)
{
    if(root == NULL) return ;
    static Node* pre=NULL;
    // Step 1
    bToDLL(root->left,head_ref);
    // Step 2
    if(*head_ref==NULL){
        *head_ref = root;
    }else{
        root->left = pre;
        pre->right = root;
    }
    pre = root;
    // Step 3 
    bToDLL(root->right,head_ref);
    
}
