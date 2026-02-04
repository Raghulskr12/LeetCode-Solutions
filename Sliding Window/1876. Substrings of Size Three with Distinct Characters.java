class Solution {
    public int countGoodSubstrings(String s) {

        // A good substring must be of length 3
        if (s.length() < 3) return 0;

        // Stores frequency of characters in the current sliding window
        HashMap<Character, Integer> charFrequency = new HashMap<>();

        int goodSubstringCount = 0;

        // Initialize the first window of size 3
        for (int i = 0; i < 3; i++) {
            char currentChar = s.charAt(i);
            charFrequency.put(currentChar,
                    charFrequency.getOrDefault(currentChar, 0) + 1);
        }

        // If all 3 characters are unique
        if (charFrequency.size() == 3) {
            goodSubstringCount++;
        }

        int leftPointer = 0;

        // Slide the window from index 3 to the end
        for (int rightPointer = 3; rightPointer < s.length(); rightPointer++) {

            // Add the new character to the window
            char rightChar = s.charAt(rightPointer);
            charFrequency.put(rightChar,
                    charFrequency.getOrDefault(rightChar, 0) + 1);

            // Remove the leftmost character from the window
            char leftChar = s.charAt(leftPointer);
            charFrequency.put(leftChar, charFrequency.get(leftChar) - 1);

            // If frequency becomes zero, remove the character
            if (charFrequency.get(leftChar) == 0) {
                charFrequency.remove(leftChar);
            }

            // Check if current window has all unique characters
            if (charFrequency.size() == 3) {
                goodSubstringCount++;
            }

            // Move the window forward
            leftPointer++;
        }

        return goodSubstringCount;
    }
}
