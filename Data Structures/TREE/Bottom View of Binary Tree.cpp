// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

void bottomView(Node* root){
    if(root == NULL){
        return ;
    }
    map<int,int> m;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        Node* temp = q.front().first;
        int x = q.front().second;
        q.pop();
        m[x]=temp->data;
        if(temp->left){
            q.push({temp->left,x-1});
        }
        if(temp->right){
            q.push({temp->right,x+1});
        }
    }
    for(auto x:m){
        cout<<x.second<<" ";
    }
}
