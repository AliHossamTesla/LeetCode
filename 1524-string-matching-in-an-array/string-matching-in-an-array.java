import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> stringMatching(String[] w) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < w.length; i++) {
            String t = w[i];
            for (int j = 0; j < w.length; j++) {
                if (i != j && w[j].contains(t)) {
                    ans.add(t);
                    break;
                }
            }
        }
        return ans;
    }
}
