class Solution {
    public int maxScore(int[] cardPoints, int k) {

        // Total points if we pick from the front
        int frontSum = 0;
        // Total points if we pick from the back
        int backSum = 0;

        int n = cardPoints.length;
        int backIndex = n - 1;   // Points to the end of the array

        // Step 1: Take k cards from the front AND from the back
        // (We will later slide the window between them)
        for (int i = 0; i < k; i++) {
            frontSum += cardPoints[i];
            backSum += cardPoints[backIndex];
            backIndex--;
        }

        int maxScore = Math.max(frontSum, backSum);

        int leftPointer = k - 1;     // Last index currently included in frontSum
        int rightPointer = n - 1;    // Last card on the right side

        // Step 2:
        // Replace 1 front card with 1 back card each step (slide the window)
        // frontSum loses a left card and gains a right card
        while (leftPointer >= 0) {
            frontSum -= cardPoints[leftPointer];  // Remove card from front
            frontSum += cardPoints[rightPointer]; // Add card from back

            maxScore = Math.max(maxScore, frontSum);

            leftPointer--;
            rightPointer--;
        }

        return maxScore;
    }
}
