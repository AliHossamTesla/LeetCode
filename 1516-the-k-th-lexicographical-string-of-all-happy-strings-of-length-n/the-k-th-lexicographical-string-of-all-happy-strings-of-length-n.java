class Solution {
    public String getHappyString(int n, int k) {
        List<String> ans = new ArrayList<>();
        bk(0, n, new StringBuilder(), ans);
        if(ans.size() < k) return "";
        else return ans.get(k - 1);
    }
    private void bk(int i, int n, StringBuilder s, List<String> ans){
        if(i == n){
            ans.add(s.toString());
            return ;
        }
        for(char c = 'a' ; c <= 'c' ; c++) if(i == 0 || c != s.charAt(i - 1)){
            s.append(c);
            bk(i + 1, n, s, ans);
            s.deleteCharAt(i);
        }
    }
}