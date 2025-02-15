class Solution {
    HashMap<Integer, Integer>mp = new HashMap<>();
    public int punishmentNumber(int n) {
        int res = 0 ;
        for(int i = 1 ; i <= n ; i ++){
            System.out.println(i);
            if(chk(Integer.toString(i * i), i)){
                res += (i * i) ;
            }
        }
        return res ;
    }
    private boolean chk(String i, int sm){
        if(i.length() == 0) return sm == 0;
        for(int j = 0 ; j < i.length() ; j ++){
            String l = i.substring(0, j + 1);
            String r = i.substring(j + 1);
            if(chk(r, sm - Integer.parseInt(l))) return true ;
        }
        return false ;
    }
}