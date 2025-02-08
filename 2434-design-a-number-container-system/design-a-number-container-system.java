class NumberContainers {
    Map<Integer, Integer>idx;
    Map<Integer, Set<Integer>> nums;
    public NumberContainers() {
        idx = new HashMap<>();
        nums = new HashMap<>();
    }
    
    public void change(int index, int number) {
        nums.putIfAbsent(number, new TreeSet<>());
        if(idx.containsKey(index)){
            nums.get(idx.get(index)).remove(index);
        }
        idx.put(index, number);
        nums.get(number).add(index);
    }
    
    public int find(int number) {
        if(!nums.containsKey(number) || nums.get(number).isEmpty()) return -1;
        return nums.get(number).iterator().next();
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */