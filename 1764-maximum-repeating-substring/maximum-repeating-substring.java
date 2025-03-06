class Solution {
    public int maxRepeating(String sequence, String word) {
        String tmp = new String(word);
        int k = 0 ;
        while(sequence.indexOf(word) != -1){
            word += tmp ;
            k ++ ;
        }
        return k;
    }
}