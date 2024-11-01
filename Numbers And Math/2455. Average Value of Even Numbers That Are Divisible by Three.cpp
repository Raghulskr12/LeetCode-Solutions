class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sumOfDivBySix = 0;   // Sum of numbers divisible by 6
        int countDivBySix = 0;    // Count of numbers divisible by 6

        // Traverse the array to find numbers divisible by 6
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 6 == 0) {           // Check if the number is divisible by 6
                sumOfDivBySix += nums[i];    // Add to the sum
                countDivBySix++;             // Increment the count
            }
        }

        // Calculate the average if there are any divisible numbers
        if(countDivBySix > 0) {
            return sumOfDivBySix / countDivBySix;  // Return the average
        }
        
        return 0;   // Return 0 if no numbers are divisible by 6
    }
};
