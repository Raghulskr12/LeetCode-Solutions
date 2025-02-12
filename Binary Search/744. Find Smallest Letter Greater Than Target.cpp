class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            int low = 0, high = letters.size() - 1;
            
            while (low <= high) {
                int mid = (low + high) / 2;
                
                if (letters[mid] > target)
                    high = mid - 1;  // Look in the left half
                else
                    low = mid + 1;   // Look in the right half
            }
            
            // The key part: `low` will point to the smallest letter greater than `target`
            return letters[low % letters.size()]; // Wrap around using `%`
        }
    };
    