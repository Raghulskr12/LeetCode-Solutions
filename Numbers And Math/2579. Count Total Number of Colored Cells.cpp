class Solution {
    public:
        long long coloredCells(int n) {
            long long totalCells = 1; // Initially, the grid has only 1 colored cell (center cell)
            long long layerCount = 1; // Tracks the number of layers added
    
            if (n == 1) return 1; // Base case: If n = 1, return the single cell
    
            // Expand the shape layer by layer
            for (int i = 0; i < n - 1; i++) {
                totalCells += (layerCount * 4); // Each layer adds (current layer * 4) new cells
                layerCount++; // Increase the layer count for next iteration
            }
    
            return totalCells; // Return the total number of colored cells
        }
    };
    