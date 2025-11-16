class Solution {
    public int lengthOfLongestSubstring(String s) {

        // Left and right pointers for the sliding window
        int left = 0, right = 0;

        // Hash array to store the last seen index of each ASCII character
        int[] lastSeen = new int[256];

        // Initialize all character last-seen values to -1
        Arrays.fill(lastSeen, -1);

        int n = s.length();
        int maxLength = 0;

        // Expand the sliding window using 'right'
        while (right < n) {

            char currentChar = s.charAt(right);

            // If the current character was seen inside the current window,
            // move 'left' to just after the previous index of this character.
            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }

            // Calculate the current window size and update maxLength
            int windowLength = right - left + 1;
            maxLength = Math.max(maxLength, windowLength);

            // Update the last seen index of the current character
            lastSeen[currentChar] = right;

            // Move the right pointer forward
            right++;
        }

        // Return the maximum length of substring without repeating characters
        return maxLength;
    }
}
