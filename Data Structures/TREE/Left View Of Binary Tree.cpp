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

/* OR*/

void leftView(Node *root)
{
   if(root == NULL){
       return ;
   }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
       int sz = q.size();
       for(int i=0;i<sz;i++){
           Node* tp = q.front();
           q.pop();
           if(i==0){
               cout<<tp->data<<" ";
           }
           if(tp->left){
               q.push(tp->left);
           }
           if(tp->right){
               q.push(tp->right);
           }
       }
    }
}


