class RandomizedSet {
    HashMap<Integer, Integer>mp ;
    List<Integer>a ;
    Random rand ;
    public RandomizedSet() {
        mp = new HashMap<>();
        a = new ArrayList<>();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        if(mp.containsKey(val)) return false ;
        mp.put(val, a.size());
        a.add(val);
        return true ;
    }
    
    public boolean remove(int val) {
        if (!mp.containsKey(val)) return false;
        int index = mp.get(val);
        int lastElement = a.get(a.size() - 1);
        a.set(index, lastElement);
        mp.put(lastElement, index);
        a.remove(a.size() - 1);
        mp.remove(val);
        return true;
    }
    
    public int getRandom() {
        int randomIndex = rand.nextInt(a.size());
        return a.get(randomIndex);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */