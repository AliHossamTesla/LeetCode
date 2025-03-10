class Solution {
    private boolean isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    public long countOfSubstrings(String s, int k) {
        char[] a = s.toCharArray();
        Map<Character, Integer> mp = new HashMap<>();
        int n = a.length ;
        int[] nxtConst = new int[n];
        int prv = n ;
        for(int i = n - 1; i >= 0 ; i --){
            nxtConst[i] = prv ;
            if(!isVowel(a[i])) prv = i ;
        }
        int l = 0, r = 0 ;
        int cnt = 0 ;
        long ans = 0 ;
        while(r < n){
            if(isVowel(a[r])){
                mp.put(a[r], mp.getOrDefault(a[r], 0) + 1);
            }else{
                cnt ++ ;
            }

            while(l <= r && cnt > k){
                if(isVowel(a[l])){
                    mp.put(a[l], mp.get(a[l]) - 1);
                    if(mp.get(a[l]) == 0){
                        mp.remove(a[l]);
                    }
                }else cnt -- ;
                l ++ ;
            }

            while(l < r && mp.size() == 5 && cnt == k){
                ans += (nxtConst[r] - r);
                if(isVowel(a[l])){
                    mp.put(a[l], mp.get(a[l]) - 1);
                    if(mp.get(a[l]) == 0){
                        mp.remove(a[l]);
                    }
                }else cnt -- ;
                l ++ ;
            }
            r ++ ;
        }  
        return ans ; 
    }
}