class Solution {
    public String minWindow(String s, String t) {

        // Sliding window pointers
        int left = 0, right = 0;

        // Stores the starting index of the minimum window found
        int minWindowStart = -1;

        // Length of the minimum window
        int minWindowLength = Integer.MAX_VALUE;

        // Frequency map for required characters (ASCII used: 256)
        int[] freqMap = new int[256];

        // Count of how many characters from 't' have been matched
        int matchedCount = 0;

        // Build initial frequency map from string t
        for (int i = 0; i < t.length(); i++) {
            freqMap[t.charAt(i)]++;
        }

        // Expand the window using the right pointer
        while (right < s.length()) {

            // If this character is needed (freq > 0), increase match count
            if (freqMap[s.charAt(right)] > 0) {
                matchedCount++;
            }

            // Reduce frequency in map (we include this char in window)
            freqMap[s.charAt(right)]--;

            // When all characters of t are matched in the current window
            while (matchedCount == t.length()) {

                // Update minimum window size
                if ((right - left + 1) < minWindowLength) {
                    minWindowLength = right - left + 1;
                    minWindowStart = left;
                }

                // Before shrinking, remove left character from window
                freqMap[s.charAt(left)]++;

                // If frequency becomes > 0, it means we lost a required char
                if (freqMap[s.charAt(left)] > 0) {
                    matchedCount--;
                }

                // Shrink window from the left
                left++;
            }

            // Move right pointer forward
            right++;
        }

        // If no valid window was found, return empty string
        return (minWindowStart == -1) 
                ? "" 
                : s.substring(minWindowStart, minWindowStart + minWindowLength);
    }
}
