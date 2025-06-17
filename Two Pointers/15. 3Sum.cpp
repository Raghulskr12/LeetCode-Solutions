class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        // Sort the array to enable two-pointer approach
        sort(nums.begin(), nums.end());
        
        // Iterate through each number as the potential first element of the triplet
        for(int first = 0; first < nums.size(); first++) {
            // Skip duplicate values for the first element
            if(first > 0 && nums[first - 1] == nums[first]) continue;
            
            // Initialize two pointers for the remaining elements
            int second = first + 1;
            int third = nums.size() - 1;
            
            while(second < third) {
                int currentSum = nums[first] + nums[second] + nums[third];
                
                if(currentSum < 0) {
                    // Sum is too small, move the left pointer right
                    second++;
                } 
                else if(currentSum > 0) {
                    // Sum is too large, move the right pointer left
                    third--;
                } 
                else {
                    // Found a valid triplet
                    result.push_back({nums[first], nums[second], nums[third]});
                    
                    // Move both pointers inward
                    second++;
                    third--;
                    
                    // Skip duplicate values for the second element
                    while(second < third && nums[second - 1] == nums[second]) second++;
                    
                    // Skip duplicate values for the third element
                    while(second < third && nums[third + 1] == nums[third]) third--;
                }
            }
        }
        return result;
    }
};