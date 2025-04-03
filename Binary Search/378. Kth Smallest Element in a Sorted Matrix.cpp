class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            vector<int> flattenedArray;
            
            // Flatten the 2D matrix into a 1D array
            for (const auto& row : matrix) {
                for (int num : row) {
                    flattenedArray.push_back(num);
                }
            }
            
            // Sort the array to get elements in ascending order
            sort(flattenedArray.begin(), flattenedArray.end());
            
            // Return the k-th smallest element (1-based index)
            return flattenedArray[k - 1];
        }
    };
    