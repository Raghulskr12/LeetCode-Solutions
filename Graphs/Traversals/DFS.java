import java.util.*;

class Solution {
    
    public void dfs1(int node, ArrayList<ArrayList<Integer>> adj, boolean[] visited,
                     ArrayList<Integer> ans)
    {
        visited[node] = true;
        ans.add(node);
        
        for(int i = 0; i < adj.get(node).size(); i++)
        {
            int neighbor = adj.get(node).get(i);
            
            if(!visited[neighbor])
            {
                dfs1(neighbor, adj, visited, ans);
            }
        }
    }
    
    public ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> adj) {
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        boolean[] visited = new boolean[adj.size()];
        
        dfs1(0, adj, visited, ans);
        
        return ans;
    }
}