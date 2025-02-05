class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Iterate through all pairs of elements in the array
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                // Check if arr[i] is double of arr[j] and ensure i != j
                if (i != j && arr[i] == arr[j] * 2) {
                    return true;  // Return true if the condition is met
                }
            }
        }
        return false;  // Return false if no such pair exists
    }
};
