class Solution {
    public int[] sumZero(int n) {
        // Create an array of size n
        int[] result = new int[n];
        
        // Number of positive-negative pairs we can form
        int pairCount = n / 2;
        
        // Index pointer for inserting values
        int index = 0;
        
        // Fill the array with pairs like (1, -1), (2, -2), ...
        for (int i = 1; i <= pairCount; i++) {
            result[index] = i;       // insert positive number
            index++;
            result[index] = -i;      // insert negative number
            index++;
        }
        
        // If n is odd, one element will remain as 0 (default in Java)
        return result;
    }
}
