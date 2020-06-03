//https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
`
void connect(Node *p)
{
    if(p==NULL){
        return;
    }
   queue<Node*> q;
   q.push(p);
   while(!q.empty()){
       int sz = q.size();
       for(int i=0;i<sz;i++){
           Node* temp = q.front();
           q.pop();
           if(i==sz-1){
               temp->nextRight = NULL;
           }else{
               temp->nextRight = q.front();
           }
           if(temp->left){
               q.push(temp->left);
           }
           if(temp->right){
               q.push(temp->right);
           }
       }
   }
}
