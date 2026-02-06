class Solution {

    // Helper function to compare two frequency arrays
    // Returns true if both have identical character counts
    public boolean areFrequenciesEqual(int[] patternFreq, int[] windowFreq) {

        // Compare all ASCII character counts
        for (int i = 0; i < 256; i++) {
            if (patternFreq[i] != windowFreq[i]) {
                return false;
            }
        }
        return true;
    }

    public boolean checkInclusion(String pattern, String text) {

        // Frequency array for pattern string
        int[] patternFreq = new int[256];

        // Frequency array for current sliding window in text
        int[] windowFreq = new int[256];

        // Build frequency count of pattern
        for (int i = 0; i < pattern.length(); i++) {
            patternFreq[pattern.charAt(i)]++;
        }

        // Left pointer of sliding window
        int left = 0;

        // Traverse text using right pointer
        for (int right = 0; right < text.length(); right++) {

            // Include current character in window
            windowFreq[text.charAt(right)]++;

            // Current window length
            int windowLength = right - left + 1;

            // Shrink window if it exceeds pattern length
            if (windowLength > pattern.length()) {

                // Remove leftmost character from window
                windowFreq[text.charAt(left)]--;

                // Move left pointer
                left++;
            }

            // If window frequency matches pattern → permutation exists
            if (areFrequenciesEqual(patternFreq, windowFreq)) {
                return true;
            }
        }

        // No permutation found
        return false;
    }
}
