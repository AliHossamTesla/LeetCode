class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True  # Strings are already equal
        
        idx = -1
        s1_list = list(s1)  # Convert s1 to a list for mutability
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                if idx == -1:
                    idx = i  # Store the first mismatch index
                else:
                    # Swap characters in the list
                    s1_list[i], s1_list[idx] = s1_list[idx], s1_list[i]
                    # Compare the modified list with s2
                    return ''.join(s1_list) == s2
        
        # If only one mismatch, return False (since no swap can fix it)
        return False