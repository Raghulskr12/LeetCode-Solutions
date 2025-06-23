class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result; // Stores the final result
        sort(nums.begin(), nums.end()); // Sort the array to enable two-pointer approach
        
        for (int first = 0; first < nums.size(); first++) {
            // Skip duplicate values for the first number
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            
            for (int second = first + 1; second < nums.size(); second++) {
                // Skip duplicate values for the second number
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                
                int third = second + 1; // Pointer for the third number
                int fourth = nums.size() - 1; // Pointer for the fourth number
                
                while (third < fourth) {
                    // Calculate the sum of all four numbers (using long to prevent overflow)
                    long long current_sum = nums[first] + nums[second];
                    current_sum += nums[third];
                    current_sum += nums[fourth];
                    
                    if (current_sum > target) {
                        fourth--; // Need a smaller sum, move fourth pointer left
                    } else if (current_sum < target) {
                        third++; // Need a larger sum, move third pointer right
                    } else {
                        // Found a valid quadruplet
                        vector<int> quadruplet = {nums[first], nums[second], nums[third], nums[fourth]};
                        result.push_back(quadruplet);
                        
                        // Move both pointers
                        third++;
                        fourth--;
                        
                        // Skip duplicates for the third number
                        while (third < fourth && nums[third] == nums[third - 1]) third++;
                        
                        // Skip duplicates for the fourth number
                        while (third < fourth && nums[fourth] == nums[fourth + 1]) fourth--;
                    }
                }
            }
        }
        return result;
    }
};