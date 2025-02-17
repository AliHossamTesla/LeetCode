class Solution {
    public int numTilePossibilities(String tiles) {
        // Use a Set to store unique sequences
        Set<String> uniqueSequences = new HashSet<>();
        
        // Generate all possible permutations for all lengths
        generatePermutations(tiles.toCharArray(), 0, uniqueSequences);
        
        // The number of unique sequences is the size of the set
        return uniqueSequences.size();
    }
    private void generatePermutations(char[] tiles, int index, Set<String> uniqueSequences) {
        if (index >= tiles.length) {
            return;
        }

        for (int i = index; i < tiles.length; i++) {
            // Swap characters to create a new permutation
            swap(tiles, index, i);

            // Add the current permutation to the set
            uniqueSequences.add(new String(tiles, 0, index + 1));

            // Recursively generate permutations for the next index
            generatePermutations(tiles, index + 1, uniqueSequences);

            // Backtrack (swap back to restore the original array)
            swap(tiles, index, i);
        }
    }

    private void swap(char[] tiles, int i, int j) {
        char temp = tiles[i];
        tiles[i] = tiles[j];
        tiles[j] = temp;
    }
}