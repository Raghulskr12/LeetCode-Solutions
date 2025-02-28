class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            vector<int> ans(nums.size(), 0); // Result array with same size as nums
            int posIndex = 0;  // Index for positive numbers
            int negIndex = 1;  // Index for negative numbers
    
            // Place positive and negative numbers at alternate indices
            for (int num : nums) {
                if (num > 0) {
                    ans[posIndex] = num;
                    posIndex += 2;  // Move to next available even index
                } else {
                    ans[negIndex] = num;
                    negIndex += 2;  // Move to next available odd index
                }
            }
            return ans;
    
            /*
            ⏳ **Brute Force Approach (O(n) extra space, O(n) time)**
            
            vector<int> pos;  // Stores all positive numbers
            vector<int> neg;  // Stores all negative numbers
            vector<int> ans;  // Stores the final rearranged array
    
            // Separate positive and negative numbers
            for (int num : nums) {
                if (num > 0) {
                    pos.push_back(num);
                } else {
                    neg.push_back(num);
                }
            }
    
            // Merge positive and negative numbers alternatively
            int j = 0, k = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i % 2 == 0) {
                    ans.push_back(pos[j]);  // Insert positive number at even index
                    j++;
                } else {
                    ans.push_back(neg[k]);  // Insert negative number at odd index
                    k++;
                }
            }
            return ans;
            */
        }
    };
    