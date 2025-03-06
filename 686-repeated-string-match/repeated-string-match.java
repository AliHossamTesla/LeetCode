class Solution {
    public int repeatedStringMatch(String a, String b) {
        List<Character> lst = new ArrayList<>();
        for(char c : b.toCharArray()) lst.add(c);
        lst.add('#');
        List<Integer> pi = new ArrayList<>();
        pi.add(0);
        for(int i = 1; i < lst.size() ; i ++){
            int j = pi.get(i - 1);
            while(j > 0 && lst.get(i) != lst.get(j)) j = pi.get(j - 1);
            if(lst.get(i) == lst.get(j)) j ++ ;
            pi.add(j);
        }
        for(int i = 0 ; i < Math.max(b.length(), 100 * a.length()) ; i ++){
            char c = a.charAt((i % a.length())) ;
            int j = pi.get(pi.size() - 1) ;
            while(j > 0 && lst.get(j) != c) j = pi.get(j - 1) ;
            if(c == lst.get(j)) j ++ ;
            if(j == b.length()){
                return i/a.length() + 1 ;
            }
            lst.add(c);
            pi.add(j);
        }
        return -1 ;
    }
}