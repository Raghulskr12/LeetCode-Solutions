class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        /* BRUTE FORCE:
        vector<int> result;

        // Add elements from arr2 to result in the relative order
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr2[i] == arr1[j]) {
                    result.emplace_back(arr1[j]);
                    arr1[j] = -1; // Mark the element as processed
                }
            }
        }

        // Sort the remaining elements of arr1
        sort(arr1.begin(), arr1.end());

        // Append non-processed elements from arr1 to result
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != -1) {
                result.emplace_back(arr1[i]);
            }
        }

        return result;
        */

        // Optimized Approach:
        int insertionIndex = 0;

        // Reorder arr1 based on the order of arr2
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr2[i] == arr1[j]) {
                    swap(arr1[insertionIndex], arr1[j]);
                    insertionIndex++;
                }
            }
        }

        // Sort the remaining elements after those in arr2
        sort(arr1.begin() + insertionIndex, arr1.end());

        return arr1;
    }
};
