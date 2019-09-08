/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Prints the nodes having no siblings.  */
set<int>s;
void printSingles(Node *root) 
{ 
    // Base case 
    if (root == NULL) 
      return; 
  
    // If this is an internal node, recur for left 
    // and right subtrees 
    if (root->left != NULL && root->right != NULL) 
    { 
        printSingles(root->left); 
        printSingles(root->right); 
    } 
  
    // If left child is NULL and right is not, print right child 
    // and recur for right child 
    else if (root->right != NULL) 
    { 
         s.insert(root->right->data);  
        printSingles(root->right); 
    } 
  
    // If right child is NULL and left is not, print left child 
    // and recur for left child 
    else if (root->left != NULL) 
    { 
        s.insert(root->left->data); 
        printSingles(root->left); 
    } 
} 
  
void printSibling(Node* node)
{
 //Base case 
    set<int>::iterator it;
    s.clear();
    printSingles(node);
    int siz=s.size();
    if(siz==0)
    {
        cout<<"-1";
    }
    else{
    int count=0;
    for(it=s.begin();it!=s.end();it++,count++)
    {
        cout<<(*it)<<" ";
    }
    }
} 
