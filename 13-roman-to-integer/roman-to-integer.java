class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);
        int prev = 1_000_000 ;
        int ans = 0 ;
        for(char c : s.toCharArray()){
            int i = mp.get(c);
            if(i > prev){
                ans += i - 2*prev ;
            }else{
                ans += i ;
            }
            prev = i ;
        }
        return ans ;
    }
}