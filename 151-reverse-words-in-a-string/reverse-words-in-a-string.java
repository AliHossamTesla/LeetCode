class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        Stack<String>cr = new Stack<>();
        for(int i = 0 ; i < n ; i ++){
            while(i < n && s.charAt(i) == ' ') i ++;
            StringBuilder tm = new StringBuilder();
            while(i < n && s.charAt(i) != ' '){
                tm.append(s.charAt(i ++));
            }
            if(tm.length() > 0){
                cr.add(tm.toString());
            }
        }
        StringBuilder ans = new StringBuilder();
        while(!cr.isEmpty()){
            ans.append(cr.pop());
            if(!cr.isEmpty()){
                ans.append(" ");
            }
        }
        return ans.toString();
    }
}