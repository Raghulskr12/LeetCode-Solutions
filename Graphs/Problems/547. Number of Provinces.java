import java.util.*;

class Solution {

    // DFS function (not used in final solution here, but kept for reference)
    public void dfs(int node, int[][] isConnected, boolean visited[]) {

        // Mark current city as visited
        visited[node] = true;

        // Check all possible cities connected to this node
        for (int i = 0; i < isConnected.length; i++) {

            // If there is a connection and the city is not visited
            if (!visited[i] && isConnected[node][i] == 1) {

                // Visit that city recursively
                dfs(i, isConnected, visited);
            }
        }
    }

    // BFS function to explore all cities in the same province
    public void bfs(int node, int[][] isConnected, boolean[] visited) {

        // Queue used for BFS traversal
        Queue<Integer> q1 = new LinkedList<>();

        // Add the starting city
        q1.add(node);

        // Mark it as visited
        visited[node] = true;

        // Process cities level by level
        while (!q1.isEmpty()) {

            // Remove a city from the queue
            node = q1.poll();

            // Check all cities connected to this city
            for (int i = 0; i < isConnected.length; i++) {

                // If city i is connected and not visited
                if (!visited[i] && isConnected[node][i] == 1) {

                    // Mark it visited
                    visited[i] = true;

                    // Add it to queue for further exploration
                    q1.offer(i);
                }
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {

        // Track visited cities
        boolean visited[] = new boolean[isConnected.length];

        int count = 0; // Number of provinces

        // Traverse each city
        for (int i = 0; i < isConnected.length; i++) {

            // If the city is not visited, it means a new province
            if (!visited[i]) {

                // Explore the entire province using BFS
                bfs(i, isConnected, visited);

                // Increase province count
                count++;
            }
        }

        return count;
    }
}