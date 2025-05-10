class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;  // To store the frequency of each number

        // Count the frequency of all numbers in the array
        for (auto num : nums) {
            frequencyMap[num]++;
        }

        int answer = 0;
        int maxPositiveWithNegative = INT_MIN;

        // Iterate through the array to find the maximum positive number 
        // that also has its negative counterpart in the array
        for (int i = 0; i < nums.size(); i++) {
            // Check if nums[i] is positive, greater than current max,
            // and its negative exists in the map
            if (nums[i] > maxPositiveWithNegative && frequencyMap[-nums[i]]) {
                answer = nums[i];
                maxPositiveWithNegative = nums[i];
            }
        }

        // If no such number is found, return -1
        if (maxPositiveWithNegative < 0) return -1;

        return answer;
    }
};
