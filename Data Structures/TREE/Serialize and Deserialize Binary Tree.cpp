// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1


void serialize(Node *root,vector<int> &A)
{
    if(root == NULL){
        A.push_back(-1);
        return;
    }
    
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}

/*this function deserializes
 the serialized vector A*/
Node* solve(queue<int>& q){
    int x = q.front();
    q.pop();
    if(x==-1){
        return NULL;
    }
    
    Node* root = new Node(x);
    // cout<<root->data<<" \n";
    root->left = solve(q);
    root->right = solve(q);
    return root;
} 
 
Node * deSerialize(vector<int> &A)
{
   queue<int> q;
   for(auto x:A){
       q.push(x);
   }
   A.clear();
   Node* root = solve(q);
   return root;
}
