class Solution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int maxSum = 0; // Sum of the chosen k items

        // Choose k items to maximize the sum
        for (int i = 0; i < k; i++) {
            if (numOnes > 0) {
                // Prefer 1s first to maximize sum
                maxSum++;
                numOnes--;
            } else if (numZeros > 0) {
                // Then choose 0s, sum remains unchanged
                numZeros--;
            } else {
                // Finally, choose -1s, sum decreases
                maxSum--;
                numNegOnes--;
            }
        }

        return maxSum;
    }
}
