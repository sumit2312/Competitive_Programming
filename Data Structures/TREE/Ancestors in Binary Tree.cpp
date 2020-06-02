// https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1/

bool printAncestors(struct Node *root, int target)
{
    if(!root) return false;
    if(root->data==target)
        return true;
    
    if(printAncestors(root->left,target) or printAncestors(root->right,target) )
    {
        cout<<root->data<<" ";
        return true;
    }
}
