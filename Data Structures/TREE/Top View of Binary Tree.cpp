// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

void topView(struct Node *root)
{
    if(root== NULL) return;
    map<int,int> m;
    queue<pair<Node*,int>> q;
    int hd=0;
    q.push({root,hd});
    while(!q.empty()){
        Node* temp = q.front().first;
        hd = q.front().second;
        if(m.find(hd)==m.end()) m[hd]=temp->data;
        if(temp->left) q.push({temp->left,hd-1});
        if(temp->right) q.push({temp->right,hd+1});
        q.pop();
    }
    for(auto x:m){
        cout<<x.second<<" ";
    }
}
