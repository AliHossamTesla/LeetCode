import java.util.*;

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, Integer> inDegree = new HashMap<>();
        Map<String, List<String>> graph = new HashMap<>();
        Set<String> available = new HashSet<>(Arrays.asList(supplies));

        // Initialize graph and in-degree
        for (int i = 0; i < recipes.length; i++) {
            String recipe = recipes[i];
            inDegree.put(recipe, ingredients.get(i).size()); // Count required ingredients

            for (String ingredient : ingredients.get(i)) {
                graph.computeIfAbsent(ingredient, k -> new ArrayList<>()).add(recipe);
            }
        }

        // Process queue with available supplies
        Queue<String> queue = new LinkedList<>(available);
        List<String> result = new ArrayList<>();

        while (!queue.isEmpty()) {
            String item = queue.poll();
            if (inDegree.containsKey(item)) { // Only add recipes
                result.add(item);
            }
            if (graph.containsKey(item)) {
                for (String recipe : graph.get(item)) {
                    inDegree.put(recipe, inDegree.get(recipe) - 1);
                    if (inDegree.get(recipe) == 0) {
                        queue.add(recipe);
                    }
                }
            }
        }
        return result;
    }
}
