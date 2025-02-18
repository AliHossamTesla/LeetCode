class Solution {
    public String smallestNumber(String p) {
        int n = p.length();
        for(char c = '1' ; c <= '9'; c ++){
            boolean[] vis = new boolean[10];
            StringBuilder res = new StringBuilder();
            res.append(c);
            vis[c - '0'] = true ;
            if(bk(1, p, res, vis)) return res.toString();
        }
        return "-1";
    }
    private boolean bk(int i, String s, StringBuilder res, boolean[] vis){
        // System.out.println(res.toString());
        if(i >= s.length() + 1){
            return true ;
        }
        if(s.charAt(i - 1) == 'I'){
            for(char c = (char)(res.charAt(i - 1) + 1); c <= '9' ; c ++)if(!vis[c - '0']){
                // System.out.println(i + " " + c);
                res.append(c);
                vis[c - '0'] = true ;
                if(bk(i + 1, s, res, vis)) return true ;
                vis[c - '0'] = false;
                res.deleteCharAt(i);
            }
        }else{
            for(char c = '1' ; c < res.charAt(i - 1) ; c ++) if(!vis[c - '0']){
                res.append(c);
                vis[c - '0'] = true ;
                if(bk(i + 1, s, res, vis)) return true ;
                vis[c - '0'] = false;
                res.deleteCharAt(i);
            }
        }
        return false ;
    }
}