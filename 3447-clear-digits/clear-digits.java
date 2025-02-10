class Solution {
    public String clearDigits(String st) {
        Deque<Character> s = new ArrayDeque<>();
        for(char i : st.toCharArray()){
            if(i >= 'a' && i <= 'z') s.push(i);
            else s.pop();
        }
        StringBuilder result = new StringBuilder();
        while (!s.isEmpty()) {
            result.append(s.pollLast()); // Append characters from the bottom of the stack
        }

        return result.toString();
    }
}