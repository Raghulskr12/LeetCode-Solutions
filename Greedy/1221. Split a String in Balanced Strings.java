class Solution {
    public int balancedStringSplit(String s) {
        int balancedCount = 0;    // Number of balanced substrings
        int leftCount = 0;        // Count of 'L' characters in current segment
        int rightCount = 0;       // Count of 'R' characters in current segment

        // Traverse through each character in the string
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'R') rightCount++;
            if (s.charAt(i) == 'L') leftCount++;

            // When left and right counts are equal, we found a balanced substring
            if (leftCount == rightCount) {
                balancedCount++;
                leftCount = 0;    // Reset counts for the next substring
                rightCount = 0;
            }
        }

        return balancedCount;
    }
}
