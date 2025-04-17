class Solution {
    public:
        int countPairs(vector<int>& numbers, int divisor) {
            int pairCount = 0; // Stores the count of valid pairs
            
            for(int i = 0; i < numbers.size(); i++) {
                for(int j = i + 1; j < numbers.size(); j++) {
                    // Check if the elements at index i and j are equal
                    // and if the product of indices is divisible by the given divisor
                    if (numbers[i] == numbers[j] && (i * j) % divisor == 0) {
                        pairCount++;
                    }
                }
            }
            
            return pairCount; // Return the total count of valid pairs
        }
    };
    