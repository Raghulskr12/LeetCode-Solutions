class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            // Create a result vector of the same size as nums to store the output
            vector<int> result(nums.size());
    
            // Loop through each index of the input array
            for (int i = 0; i < nums.size(); i++) {
                // At each index i, set result[i] to nums[nums[i]]
                // This creates a new array where each element is replaced by the element at the index of its current value
                result[i] = nums[nums[i]];
            }
    
            // Return the newly built array
            return result;
        }
    };
    