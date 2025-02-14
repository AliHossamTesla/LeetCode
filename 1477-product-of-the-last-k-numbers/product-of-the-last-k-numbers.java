class ProductOfNumbers {
    private int sz;
    ArrayList<Integer>lt;
    public ProductOfNumbers() {
        lt = new ArrayList<>();
        lt.add(1);
    }
    
    public void add(int num) {
        if(num == 0){
            sz = 0 ;
            lt = new ArrayList<>();
            lt.add(1);
        }else{
            sz ++ ;
            lt.add(lt.getLast() * num);
        }
    }
    
    public int getProduct(int k) {
        if(k > sz) return 0;
        else return lt.get(sz)/lt.get(sz - k);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */