class Solution {
    private class DSU {
        private int[] parent;
        private int[] rank;
        private int[] size; // Array to store the size of each set
        private int n; // Number of rows
        private int m; // Number of columns

        public DSU(int n, int m) {
            this.n = n;
            this.m = m;
            int totalNodes = n * m; // Total number of nodes in the grid
            parent = new int[totalNodes];
            rank = new int[totalNodes];
            size = new int[totalNodes]; // Initialize size array
            for (int i = 0; i < totalNodes; i++) {
                parent[i] = i; // Each node is its own parent initially
                rank[i] = 1;   // Each node has rank 1 initially
                size[i] = 1;   // Each set initially contains 1 element
            }
        }

        // Convert 2D coordinates (x, y) to 1D index
        private int transfer(int x, int y) {
            return x * m + y;
        }

        // Convert 1D index back to 2D coordinates (x, y)
        private int[] inverseTransfer(int i) {
            return new int[]{i / m, i % m};
        }

        // Find the root of the set containing (x, y)
        public int find(int x, int y) {
            int index = transfer(x, y);
            if (parent[index] != index) {
                parent[index] = find(inverseTransfer(parent[index])[0], inverseTransfer(parent[index])[1]); // Path compression
            }
            return parent[index];
        }

        // Union two sets containing (x1, y1) and (x2, y2)
        public boolean union(int x1, int y1, int x2, int y2) {
            int rootX = find(x1, y1);
            int rootY = find(x2, y2);

            if (rootX == rootY) {
                return false; // Already in the same group (cycle detected)
            }

            // Union by rank
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX]; // Update the size of the set
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY]; // Update the size of the set
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY]; // Update the size of the set
            }

            return true; // Successfully merged
        }

        // Get the size of the set containing (x, y)
        public int getSize(int x, int y) {
            int root = find(x, y);
            return size[root];
        }
    }
    int[][] dir = {{1, 0}, {-1, 0}, {0, 1},{0, -1}};
    public int largestIsland(int[][] a) {
        int n = a.length;
        int m = a[0].length;
        DSU d = new DSU(n, m);
        boolean[][] vis = new boolean[n][m];
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++) if(!vis[i][j] && a[i][j] == 1){
                floodfill(i, j, a, vis, d, n, m);
                ans = Math.max(ans, d.getSize(i, j));
            }
        }
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++) if(a[i][j] == 0){
                Set<Integer> uniqueRoots = new HashSet<>();
                int cr = 1 ;
                for(int[] dir_ : dir){
                    int di = i + dir_[0];
                    int dj = j + dir_[1];
                    if(di >= 0 &&  di < n && dj >= 0 && dj < m && a[di][dj] != 0 && uniqueRoots.add(d.find(di, dj))){
                        cr += d.getSize(di, dj);
                    }
                }
                ans = Math.max(ans, cr);
            }
        }
        return ans ;
    }
    private void floodfill(int x, int y, int[][] a, boolean[][] vis, DSU d, int n, int m){
        vis[x][y] = true ;
        for(int[] dir_ : dir){
            int dx = x + dir_[0];
            int dy = y + dir_[1];
            if(dx >= 0 &&  dx < n && dy >= 0 && dy < m && a[dx][dy] != 0 && !vis[dx][dy]){
                d.union(x, y, dx, dy);
                floodfill(dx, dy, a, vis, d, n, m);
            }
        }
    }
}