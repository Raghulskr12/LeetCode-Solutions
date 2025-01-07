class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = -1; // Variable to store the majority element
        int size = nums.size();  // Size of the input array
        unordered_map<int, int> frequency; // Hash map to store the frequency of each element

        // Count the frequency of each element in the array
        for (auto number : nums) {
            frequency[number]++;
        }

        // Iterate through the frequency map to find the majority element
        for (auto element : frequency) {
            if (element.second > size / 2) { // Check if the count of the element is more than n/2
                majorityElement = element.first;
            }
        }

        return majorityElement; // Return the majority element
    }
};
