class Solution {
    public:
        vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int target) {
            int occurrenceCount = 0; // Count occurrences of target in nums
            vector<int> targetIndices; // Stores indices where target appears
            vector<int> result; // Stores the output for each query
    
            // Traverse the nums array to find occurrences of target
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    occurrenceCount++; 
                    targetIndices.push_back(i);
                }
            }
    
            // Sort the indices (though they are already in order)
            sort(targetIndices.begin(), targetIndices.end());
    
            // Process each query to find the k-th occurrence of target
            for (int i = 0; i < queries.size(); i++) {
                if (queries[i] > occurrenceCount) {
                    result.push_back(-1); // If k is out of bounds, return -1
                } else {
                    result.push_back(targetIndices[queries[i] - 1]); // Return k-th occurrence index
                }
            }
            
            return result;
        }
    };
    