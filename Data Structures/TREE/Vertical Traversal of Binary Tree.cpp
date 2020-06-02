// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

void verticalOrder(Node *root)
{
    if(root==NULL){
        return;
    }
    queue<pair<Node*,int>>q;
    map<int,vector<int>> m;
    q.push({root,0});
    while(!q.empty()){
        Node* temp = q.front().first;
        int x = q.front().second;
        q.pop();
        m[x].push_back(temp->data);
        if(temp->left){
            q.push({temp->left,x-1});
        }
        if(temp->right){
            q.push({temp->right,x+1});
        }
    }
    for(auto x:m){
        vector<int> c;
        c= x.second;
        for(auto to:c){
            cout<<to<<" ";
        }
    }
}
