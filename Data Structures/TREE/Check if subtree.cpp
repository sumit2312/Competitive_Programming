//https://practice.geeksforgeeks.org/problems/check-if-subtree/1

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
bool is(Node* r1,Node* r2){
    return r1 && r2 && r1->data==r2->data && is(r1->left,r2->left) && is(r1->right,r2->right) || !r1 && !r2; 
}

bool isSubTree(Node* T, Node* S) {
    return is(T,S) || (T && (isSubTree(T->left,S) || isSubTree(T->right,S)));
}
