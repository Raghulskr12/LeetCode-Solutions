class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int low = 0;
            int high = arr.size() - 1;
            
            // Binary Search Approach
            while (low <= high) {
                int mid = (low + high) / 2;
                int missingCount = arr[mid] - (mid + 1); // Number of missing numbers before arr[mid]
                
                if (missingCount < k) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            return k + high + 1; // Adjust based on missing count
            
            /*
            // Brute Force Approach
            int missingCount = 0;
            unordered_map<int, int> present;
            
            // Store all elements of arr in a hashmap
            for (int num : arr) {
                present[num]++;
            }
            
            // Iterate from 1 to a large number and count missing elements
            for (int i = 1; i <= 5000; i++) {
                if (present[i] == 0) {
                    missingCount++;
                }
                if (missingCount == k) {
                    return i;
                }
            }
            return 0;
            */
        }
    };
    