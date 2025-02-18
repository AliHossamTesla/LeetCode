class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        gen(new StringBuilder(), 0, ans, 2*n);
        return ans ;
    }
    private void gen(StringBuilder s, int cr, List<String> ans, int n){
        if(cr < 0) return ;
        if(cr > (n - s.length())) return ;
        if(s.length() == n){
            // System.out.println(cr + " " + s.toString()) ;
            if(cr == 0) ans.add(s.toString());
            return ;
        }
        s.append('(');
        gen(s, cr + 1, ans, n);
        s.deleteCharAt(s.length() - 1);
        s.append(')');
        gen(s, cr - 1, ans, n);
        s.deleteCharAt(s.length() - 1);
    }
}