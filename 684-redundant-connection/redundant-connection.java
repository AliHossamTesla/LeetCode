class Solution {
    public int[] findRedundantConnection(int[][] e) {
        DSU d = new DSU(e.length);
        for(int i = 0 ; i < e.length ; i ++){
            if(d.mergeGroups(e[i][0], e[i][1]) == 0){
                return (new int[]{e[i][0], e[i][1]});
            }
        }
        return new int[]{-1};
    }
}
class DSU {
    int[] parent, groupSize;
    int numberOfNodes, numberOfGroups, maxGroup;

    public DSU(int numberOfNodes) {
        this.numberOfNodes = numberOfNodes;
        parent = new int[numberOfNodes + 1];
        groupSize = new int[numberOfNodes + 1];
        numberOfGroups = numberOfNodes;
        maxGroup = 1;
        for (int i = 1; i <= numberOfNodes; i++) {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }

    public int getLeader(int x) {
        return parent[x] = (parent[x] == x ? x : getLeader(parent[x]));
    }

    public boolean sameGroup(int x, int y) {
        return getLeader(x) == getLeader(y);
    }

    public long mergeGroups(int x, int y) {
        int leader1 = getLeader(x);
        int leader2 = getLeader(y);
        if (leader1 != leader2) {
            numberOfGroups--;
            if (groupSize[leader1] < groupSize[leader2]) {
                int temp = leader1;
                leader1 = leader2;
                leader2 = temp;
            }
            parent[leader2] = leader1;
            long v = groupSize[leader2] * (long) (groupSize[leader2] - 1) / 2;
            v += groupSize[leader1] * (long) (groupSize[leader1] - 1) / 2;
            groupSize[leader1] += groupSize[leader2];
            maxGroup = Math.max(maxGroup, groupSize[leader1]);
            return groupSize[leader1] * (long) (groupSize[leader1] - 1) / 2 - v;
        }else {
            return 0;
        }
    }

    public int getSize(int x) {
        return groupSize[getLeader(x)];
    }
}