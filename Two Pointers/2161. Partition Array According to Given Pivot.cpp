class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> ans;  // Stores the final result
            int equal = 0;    // Count occurrences of pivot
    
            // Optimized Approach: Directly constructing the result in one pass
            // Step 1: Append elements smaller than pivot
            for (int num : nums) {
                if (num < pivot) ans.push_back(num);
            }
    
            // Step 2: Append elements equal to pivot
            for (int num : nums) {
                if (num == pivot) ans.push_back(num);
            }
    
            // Step 3: Append elements greater than pivot
            for (int num : nums) {
                if (num > pivot) ans.push_back(num);
            }
    
            return ans;
    
            /*
            // Brute Force Approach (Commented Out)
            // Uses extra space for three separate arrays
    
            vector<int> low, high, ans;
            int equal = 0;
    
            // Step 1: Categorizing elements into three separate vectors
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] < pivot) low.push_back(nums[i]);  // Smaller elements
                else if(nums[i] == pivot) equal++;          // Count pivot occurrences
                else high.push_back(nums[i]);               // Greater elements
            }
    
            // Step 2: Constructing final answer by merging
            for(int i = 0; i < low.size(); i++) ans.push_back(low[i]);
            for(int i = 0; i < equal; i++) ans.push_back(pivot);
            for(int i = 0; i < high.size(); i++) ans.push_back(high[i]);
    
            return ans;
            */
        }
    };
    