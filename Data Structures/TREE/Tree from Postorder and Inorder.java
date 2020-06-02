// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/

class GfG {
    // Complete the function
    int index;
    Node buildTree(int in[], int post[], int n) {
        index = n-1;
        Node ans = solve(in,post,0,n-1);
        return ans;
    }
    Node solve(int in[],int post[],int s,int e){
        if(s>e){
            return null;
        }
        Node root = new Node(post[index--]);
        
        int id=0;
        for(int i=s;i<=e;i++){
            if(in[i]==root.data){
                id=i;
                break;
            }
        }
        //One important observation is, we recursively call for right subtree before left 
        //subtree as we decrease index of postorder index whenever we create a new node.
        root.right = solve(in,post,id+1,e);
        root.left = solve(in,post,s,id-1);
        return root;
    }
}
