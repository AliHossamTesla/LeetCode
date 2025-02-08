import java.util.*;

class NumberContainers {
    private Map<Integer, Integer> idx = new HashMap<>();
    private Map<Integer, TreeSet<Integer>> nums = new HashMap<>();

    public void change(int index, int number) {
        int prevNumber = idx.getOrDefault(index, -1);
        
        // Remove index from the previous number's set if the number changes
        if (prevNumber != -1 && prevNumber != number) {
            nums.get(prevNumber).remove(index);
        }
        
        idx.put(index, number);
        
        // Add index to the new number's set
        nums.computeIfAbsent(number, k -> new TreeSet<>()).add(index);
    }

    public int find(int number) {
        TreeSet<Integer> indices = nums.get(number);
        return (indices == null || indices.isEmpty()) ? -1 : indices.first();
    }
}
