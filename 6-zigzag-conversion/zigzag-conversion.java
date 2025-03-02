class Solution {
    public String convert(String s, int numRows) {
        int n = s.length();
        List<Character>[] lst = new List[numRows];
        for(int i = 0 ; i < numRows; i ++) lst[i] = new ArrayList<>();
        int trg = 0 ;
        int j = 0 ;
        while(j < n){
            if(trg == 0){
                for(int i = 0 ; i < numRows && j < n; i ++){
                    lst[i].add(s.charAt(j++));
                }
            }else{
                for(int i = numRows - 2 ; i > 0 && j < n; i --){
                    lst[i].add(s.charAt(j ++));
                }
            }
            trg = 1 - trg ;
        }
        StringBuilder ans = new StringBuilder();
        for(int i = 0 ; i < numRows ; i ++){
            for(char c : lst[i]){
                ans.append(c);
            }
        }
        return ans.toString();
    }
}