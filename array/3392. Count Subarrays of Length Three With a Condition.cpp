class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int validSubarrays = 0; // To count the number of valid subarrays
    
            // Loop through each element except the first and last
            for (int i = 1; i < nums.size() - 1; i++) {
                // Check if the sum of neighbors equals half of the middle element
                if ((nums[i - 1] + nums[i + 1]) == ((float)nums[i] / 2)) {
                    validSubarrays++;
                }
            }
    
            return validSubarrays;
        }
    };
    