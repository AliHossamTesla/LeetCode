/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        List<List<Node>> lev = new ArrayList<>();
        dfs(root, lev, 0);
        for(int i = 0 ; i < lev.size() ; i ++){
            for(int j = 0 ; j < lev.get(i).size() - 1; j ++){
                lev.get(i).get(j).next = lev.get(i).get(j + 1);
            }
        }
        return root ;
    }
    private void dfs(Node r, List<List<Node>> lev, int cnt){
        if(r == null) return ;
        // System.out.println(cnt);
        // System.out.println("val : " + r.val);
        if(cnt >= lev.size()) lev.add(new ArrayList<>());
        lev.get(cnt).add(r);
        dfs(r.left, lev, cnt + 1);
        dfs(r.right, lev, cnt + 1);
    }
}