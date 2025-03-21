class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, Integer> enc = new HashMap<>();
        int cr = 0 ;
        List<String> name = new ArrayList<>();
        for(String s : recipes) if(!enc.containsKey(s)){
            enc.put(s, cr++);
            name.add(s);
        }
        int cnt = cr ;
        for(List<String> ss : ingredients){
            for(String s : ss){
                if(!enc.containsKey(s)){
                    enc.put(s, cr++);
                    name.add(s);
                }
            }
        }
        for(String s : supplies){
            if(!enc.containsKey(s)){
                    enc.put(s, cr++);
                    name.add(s);
            }
        }
        int[] deg = new int[cr] ;
        int n = recipes.length ;
        List<Integer>[] adj = new List[cr];
        for(int i = 0 ; i < cr ; i ++) adj[i] = new ArrayList<>();
        for(int i = 0 ; i < n ; i ++){
            for(String s : ingredients.get(i)){
                adj[enc.get(s)].add(enc.get(recipes[i]));
                deg[enc.get(recipes[i])] ++ ;
            }
        }
        List<String> ans = new ArrayList<>();
        ArrayDeque<Integer> q = new ArrayDeque<>();
        for(String s : supplies){
            q.add(enc.get(s));
        }
        while(!q.isEmpty()){
            int u = q.poll();
            if(u < cnt) ans.add(name.get(u));
            for(int v : adj[u]){
                if(--deg[v] == 0){
                    q.add(v);
                }
            }
        }
        return ans ;
    }
}