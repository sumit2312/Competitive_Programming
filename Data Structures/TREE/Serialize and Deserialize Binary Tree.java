// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null){
            return "X";
        }
        String l = serialize(root.left);
        String r = serialize(root.right);
        return root.val+","+l+","+r;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Queue<String> nodesLeft = new LinkedList<>();
        nodesLeft.addAll(Arrays.asList(data.split(",")));
        return deserializeHelper(nodesLeft);
    }
    
    public TreeNode deserializeHelper(Queue<String> nodesLeft){
        String val = nodesLeft.remove();
        if(val.equals("X")){
            return null;
        }
        TreeNode newNode = new TreeNode(Integer.valueOf(val));
        newNode.left = deserializeHelper(nodesLeft);
        newNode.right = deserializeHelper(nodesLeft);
        return newNode;
    }
    
}
