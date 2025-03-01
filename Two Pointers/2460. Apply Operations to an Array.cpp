class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int zeroCount = 0;  // To count the number of zeros
            vector<int> result; // Stores the final rearranged array
    
            // Step 1: Modify the array by doubling adjacent equal elements and setting the second to zero
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    nums[i] *= 2;    // Double the current element
                    nums[i + 1] = 0; // Set the next element to zero
                }
            }
    
            // Step 2: Count zeros and collect non-zero elements in 'result'
            for (int num : nums) {
                if (num == 0) zeroCount++;
                else result.emplace_back(num);
            }
    
            // Step 3: Append all counted zeros at the end of the 'result' array
            for (int i = 0; i < zeroCount; i++) {
                result.emplace_back(0);
            }
    
            return result;
    
            /*
            ✅ **Brute Force Approach (O(n²))**
    
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    nums[i] *= 2;    // Double the first element
                    nums[i + 1] = 0; // Set the next to zero
                }
            }
    
            // Move all zeros to the end while maintaining relative order
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    for (int j = i + 1; j < nums.size(); j++) {
                        if (nums[j] > 0) {
                            swap(nums[i], nums[j]); // Swap zero with the next non-zero
                            break;
                        }
                    }
                }
            }
    
            return nums;
            */
        }
    };
    