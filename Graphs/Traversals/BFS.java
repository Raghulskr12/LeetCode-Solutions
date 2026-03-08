    import java.util.*;

class Solution {
    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        boolean[] visited = new boolean[adj.size()];
        
        Queue<Integer> q1 = new LinkedList<>();
        
        q1.add(0);
        visited[0] = true;
        
        while(!q1.isEmpty())
        {
            int node = q1.poll();
            ans.add(node);
            
            for(int i = 0; i < adj.get(node).size(); i++)
            {
                int neighbor = adj.get(node).get(i);
                
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q1.offer(neighbor);
                }
            }
        }
        
        return ans;
    }
}