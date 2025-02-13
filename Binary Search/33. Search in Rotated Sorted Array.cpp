class Solution {
    public:
        int search(vector<int>& arr, int k) {
            int low = 0, high = arr.size() - 1;
    
            while (low <= high) {
                int mid = (low + high) / 2;
    
                if (arr[mid] == k) return mid; // Found the element, return index
    
                // **Check if the left half [low..mid] is sorted**
                if (arr[low] <= arr[mid]) {
                    if (arr[low] <= k && k < arr[mid]) // Target lies within left half
                        high = mid - 1;
                    else 
                        low = mid + 1;
                }
                // **Otherwise, the right half [mid..high] must be sorted**
                else {
                    if (arr[mid] < k && k <= arr[high]) // Target lies within right half
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
    
            return -1; // Target not found
        }
    };
    