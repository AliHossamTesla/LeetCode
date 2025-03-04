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
    static int cnt = -1 ;
    int[] val = new int[10005];
    List<Integer>[] adj = new List[10005];
    int[][] dp;
    public int rob(TreeNode root) {
        cnt = -1 ;
        for(int i = 0 ; i < 10005 ; i ++) adj[i] = new ArrayList<>();
        dfs(root, -1);
        dp = new int[cnt + 1][2];
        for(int i = 0 ; i <= cnt ; i ++) dp[i][0] = dp[i][1] = -1 ;
        return calc(0, -1, 0);
    }
    private int calc(int u, int p, int st){
        if(dp[u][st] != -1) return dp[u][st];
        int tk = 0, ntk = 0 ;
        for(int v : adj[u]) if(v != p){
            tk  += calc(v, u, 1);
            ntk += calc(v, u, 0);
        }
        if(st == 0) tk += val[u];
        return dp[u][st] = Math.max(tk, ntk) ;
    }
    private void dfs(TreeNode r, int prv){
        if(r == null) return ;
        cnt ++ ;
        int u = cnt ;
        val[u] = r.val ;
        if(prv != -1){
            adj[prv].add(u);
            adj[u].add(prv);
        }
        dfs(r.left, u);
        dfs(r.right, u);
    }
}