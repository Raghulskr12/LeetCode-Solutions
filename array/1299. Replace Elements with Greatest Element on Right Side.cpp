class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        // Initialize the answer vector with the same size as input, filled with 0s
        vector<int> answer(nums.size(), 0);
        
        // The last element in the answer is always -1 as there's no element to its right
        answer[nums.size() - 1] = -1;
        
        // Keep track of the maximum element found so far when moving from right to left
        int maxSoFar = nums[nums.size() - 1];
        
        // Iterate through the array from right to left (starting from second last element)
        for (int i = nums.size() - 2; i >= 0; i--) {
            // The current element's answer is the maximum element to its right
            answer[i] = maxSoFar;
            
            // Update the maximum if the current element is larger
            if (nums[i] > maxSoFar) {
                maxSoFar = nums[i];
            }
        }
        
        return answer;
    }
};