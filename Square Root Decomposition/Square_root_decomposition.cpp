#include<bits/stdc++.h>
using namespace std;

int query(int *blocks,int *a,int l,int r,int rn){
    int ans=0;
    // Left Part
    while(l<r && l!=0 && l%rn!=0){
        ans+=a[l];
        l++;
    }

    // Middle Part
    while(l+rn<=r){
        int block_id = l/rn;    // index of block is i/sqrt(n)
        ans+=blocks[block_id];
        l+=rn;
    }

    // Right Part
    while(l<=r){
        ans+=a[l];
        l++;
    }
    return ans;
}

void update(int *blocks,int *a,int index,int val,int rn){
    int block_id = index/rn;
    blocks[block_id] -= a[index];
    blocks[block_id] += val;
    a[index] = val;
}


int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int rn = sqrt(n);
    int block_id = -1;
    int *blocks = new int[rn+1]{0};
    for(int i=0;i<n;i++){
        if(i%rn==0){
            block_id++;
        }
        blocks[block_id]+=a[i];
    }

    // Queries
    int l,r;
    cin>>l>>r;
    cout<<query(blocks,a,l,r,rn)<<"\n";
    update(blocks,a,2,15,rn);
    cout<<query(blocks,a,l,r,rn)<<"\n";
}
