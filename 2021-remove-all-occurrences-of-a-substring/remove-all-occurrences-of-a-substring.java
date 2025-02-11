import java.util.*;

class Solution {
    public String removeOccurrences(String s, String part) {
        int m = part.length();
        char[] t = (part + "#" + s).toCharArray();
        
        Deque<Character> ans = new ArrayDeque<>();
        List<Integer> pi = new ArrayList<>();
        pi.add(0);
        
        for (int i = 1; i < t.length; i++) {  // Start from s's first character
            char ch = t[i];
            int j = pi.get(pi.size() - 1);
            
            while (j > 0 && ch != part.charAt(j)) {
                j = pi.get(j - 1);
            }
            
            if (ch == part.charAt(j)) j++;
            
            pi.add(j);
            if(i > m){
                ans.addLast(ch);
            }
            
            if (j == m) {  // Full match found
                for (int k = 0; k < m; k++) {
                    ans.removeLast();
                    pi.remove(pi.size() - 1);
                }
            }
        }
        
        // Build the final string
        StringBuilder result = new StringBuilder();
        for (char c : ans) {
            result.append(c);
        }
        return result.toString();
    }
}
