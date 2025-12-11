class Solution {
    public int characterReplacement(String s, int k) {

        // Left and right pointers for the sliding window
        int left = 0, right = 0;

        // Stores the maximum length of a valid window
        int maxWindowLength = 0;

        // Stores the highest frequency of any single character in the current window
        int maxCharFrequency = 0;

        // Frequency array to count occurrences of A-Z characters in the window
        int[] charCount = new int[26];

        // Expand the sliding window using the right pointer
        while (right < s.length()) {

            // Update count for the current right character
            charCount[s.charAt(right) - 'A']++;

            // Update the maximum frequency of any character seen so far in the window
            maxCharFrequency = Math.max(maxCharFrequency, charCount[s.charAt(right) - 'A']);

            // Check if the window is valid (i.e., we need at most k replacements)
            // If replacements needed > k, shrink window from left
            if ((right - left + 1) - maxCharFrequency > k) {
                charCount[s.charAt(left) - 'A']--;
                left++; // Shrink window
            }

            // Update the maximum valid window length
            maxWindowLength = Math.max(maxWindowLength, right - left + 1);

            // Move right pointer forward
            right++;
        }

        return maxWindowLength;
    }
}
