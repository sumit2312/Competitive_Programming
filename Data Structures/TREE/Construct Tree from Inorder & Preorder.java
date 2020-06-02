
// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

class GfG
{
    public static int preIndex;
    GfG(int ind)
    {
        preIndex = ind;
    }
    
  public static Node buildTree(int ino[], int pre[], int st, int end)
    {
        if(st>end){
           return null;
        }
        Node root = new Node(pre[preIndex++]);
        int index=0;
        for(int i=st;i<=end;i++){
            if(ino[i]==root.data){index=i;break;}
        }
        root.left=buildTree(ino,pre,st,index-1);
        root.right=buildTree(ino,pre,index+1,end);
        return root;
    }
}
