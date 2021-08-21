/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int max(int a,int b){return a>b?a:b;}
    public int maxDepthAUX(TreeNode driver, int depth){
        if(driver.left == null && driver.right == null)
            return depth;
        int leftH = 0, rightH = 0;
        if(driver.left != null){
            leftH = maxDepthAUX(driver.left, depth+1);
        }
        if(driver.right != null){
            rightH = maxDepthAUX(driver.right, depth+1);
        }
        return max(leftH, rightH);
    }
    
    public int maxDepth(TreeNode root) {
        if(root == null)
            return 0;
        
        return maxDepthAUX(root, 1);
    }
}