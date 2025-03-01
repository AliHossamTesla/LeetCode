class Solution {
    public String intToRoman(int num) {
        Map<Integer, String> mp = new HashMap<>();
        mp.put(1000, "M");
        mp.put(500, "D");
        mp.put(100, "C");
        mp.put(50, "L");
        mp.put(10, "X");
        mp.put(5, "V");
        mp.put(1, "I");
        mp.put(900, "CM");
        mp.put(400, "CD");
        mp.put(90, "XC");
        mp.put(40, "XL");
        mp.put(9, "IX");
        mp.put(4, "IV");
        int[] a = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        StringBuilder ans = new StringBuilder();
        for(int i : a){
            while(num >= i){
                num -= i ;
                ans.append(mp.get(i));
            }
        }
        return ans.toString();
    }
}