class Solution {

    // Helper function to compare two frequency arrays
    // Returns true if both arrays have identical character counts
    public boolean areFrequenciesEqual(int[] windowFreq, int[] patternFreq) {

        // Compare all ASCII character counts
        for (int i = 0; i < 256; i++) {
            if (windowFreq[i] != patternFreq[i]) {
                return false;
            }
        }

        return true;
    }

    public List<Integer> findAnagrams(String text, String pattern) {

        // Result list to store starting indices of anagrams
        List<Integer> resultIndices = new ArrayList<>();

        // Frequency array for current sliding window in text
        int[] windowFreq = new int[256];

        // Frequency array for the pattern string
        int[] patternFreq = new int[256];

        // Left pointer of sliding window
        int left = 0;

        // Precompute frequency of pattern characters
        for (int i = 0; i < pattern.length(); i++) {
            patternFreq[pattern.charAt(i)]++;
        }

        // Expand the sliding window using right pointer
        for (int right = 0; right < text.length(); right++) {

            // Include current character into window frequency
            windowFreq[text.charAt(right)]++;

            // Current window length
            int windowLength = right - left + 1;

            // Shrink window if it exceeds pattern length
            while (windowLength > pattern.length()) {

                // Remove leftmost character from window
                windowFreq[text.charAt(left)]--;

                // Move left pointer forward
                left++;

                // Update window length
                windowLength = right - left + 1;
            }

            // If window frequencies match pattern → anagram found
            if (areFrequenciesEqual(windowFreq, patternFreq)) {
                resultIndices.add(left);
            }
        }

        return resultIndices;
    }
}
