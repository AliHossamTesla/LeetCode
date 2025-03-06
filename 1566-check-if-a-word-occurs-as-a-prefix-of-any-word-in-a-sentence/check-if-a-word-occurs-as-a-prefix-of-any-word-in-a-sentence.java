class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        searchWord += '#';
        int[] pi = new int[searchWord.length()];
        for(int i = 1; i < searchWord.length() ; i ++){
            int j = pi[i - 1] ;
            while(j > 0 && searchWord.charAt(i) != searchWord.charAt(j)) j = pi[j - 1];
            if(searchWord.charAt(i) == searchWord.charAt(j)) j ++ ;
            pi[i] = j ;
        }
        int prv = pi[searchWord.length() - 1];
        int wordNumber = 1 ;
        int cnt = 0 ;
        for(char c : sentence.toCharArray()){
            if(c == ' '){
                wordNumber ++ ;
                prv = 0 ;
                cnt = 0 ;
                continue ;
            }
            cnt ++ ;
            int j = prv ;
            while(j > 0 && c != searchWord.charAt(j)) j = pi[j - 1];
            if(c == searchWord.charAt(j)) j ++  ;
            if(j == searchWord.length() - 1 && cnt == j) return wordNumber ;;
            prv = j ;
        } 
        return -1 ;
    }
}