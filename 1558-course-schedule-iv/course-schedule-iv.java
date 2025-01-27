import java.util.*;

class Solution {
    public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
        // Build adjacency list
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] edge : prerequisites) {
            int u = edge[0], v = edge[1];
            adj[u].add(v);
        }

        // Initialize reachability matrix
        boolean[][] reachable = new boolean[n][n];

        // Perform BFS for each node to find all reachable nodes
        for (int i = 0; i < n; i++) {
            Queue<Integer> queue = new LinkedList<>();
            queue.offer(i);
            while (!queue.isEmpty()) {
                int u = queue.poll();
                for (int v : adj[u]) {
                    if (!reachable[i][v]) {
                        reachable[i][v] = true;
                        queue.offer(v);
                    }
                }
            }
        }

        // Answer the queries
        List<Boolean> ans = new ArrayList<>();
        for (int[] query : queries) {
            int u = query[0], v = query[1];
            ans.add(reachable[u][v]);
        }

        return ans;
    }
}