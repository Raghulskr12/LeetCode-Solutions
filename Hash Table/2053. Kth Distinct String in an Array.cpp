class Solution {
    public:
        string kthDistinct(vector<string>& arr, int k) {
            unordered_map<string, int> frequency;  // Map to store frequency of each string
            
            // Count occurrences of each string in the array
            for (const auto& str : arr) {
                frequency[str]++;
            }
            
            int distinctCount = 0;  // Counter for distinct elements
            
            // Iterate through the array again to find the k-th distinct element
            for (int i = 0; i < arr.size(); i++) {
                if (frequency[arr[i]] == 1) {  // Check if the string appears only once
                    distinctCount++;  
                    if (distinctCount == k) { // If it's the k-th distinct string, return it
                        return arr[i];
                    }
                }
            }
            
            return "";  // Return an empty string if there is no k-th distinct element
        }
    };
    