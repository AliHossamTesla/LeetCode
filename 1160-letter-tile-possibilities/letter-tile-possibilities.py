class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        from itertools import permutations
        
        # Use a set to store unique sequences
        unique_sequences = set()
        
        # Iterate over all possible lengths of sequences
        for length in range(1, len(tiles) + 1):
            # Generate all permutations of the current length
            for perm in permutations(tiles, length):
                # Add the permutation to the set
                unique_sequences.add(perm)
        
        # The number of unique sequences is the size of the set
        return len(unique_sequences)