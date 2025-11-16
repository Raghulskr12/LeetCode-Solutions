class Solution {

    // Helper function to check if a character is a vowel
    public boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    public int maxVowels(String s, int k) {

        int currentVowelCount = 0; // number of vowels in current window
        int maxVowelsInWindow = 0; // maximum vowels found in any window of size k

        // Step 1: Count vowels in the initial window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s.charAt(i))) {
                currentVowelCount++;
            }
        }

        // Initial max
        maxVowelsInWindow = currentVowelCount;

        // Step 2: Slide the window from index k to end of string
        for (int right = k; right < s.length(); right++) {

            // Add the new rightmost character to window
            if (isVowel(s.charAt(right))) {
                currentVowelCount++;
            }

            // Remove the leftmost exiting character
            int left = right - k;
            if (isVowel(s.charAt(left))) {
                currentVowelCount--;
            }

            // Update maximum vowels found so far
            maxVowelsInWindow = Math.max(maxVowelsInWindow, currentVowelCount);
        }

        return maxVowelsInWindow;
    }
}
