class Solution {
    public List<String> removeAnagrams(String[] words) {
        // Create a list to store the final result (non-consecutive anagrams)
        List<String> result = new ArrayList<>();

        // Always add the first word to the result list
        result.add(words[0]);

        // Convert the first word into a sorted version (to compare anagrams)
        char[] firstWordChars = words[0].toCharArray();
        Arrays.sort(firstWordChars);
        String previousSorted = new String(firstWordChars); // stores sorted form of previous word

        // Start checking from the second word onwards
        for (int i = 1; i < words.length; i++) {
            // Convert the current word to a sorted version
            char[] currentWordChars = words[i].toCharArray();
            Arrays.sort(currentWordChars);
            String currentSorted = new String(currentWordChars);

            // If the current sorted word equals the previous sorted word,
            // it means both are anagrams → skip adding to the result
            if (currentSorted.equals(previousSorted)) {
                continue;
            } 
            // Otherwise, add it to the result and update the "previousSorted" pattern
            else {
                result.add(words[i]);
                previousSorted = currentSorted;
            }
        }

        // Return the final list without consecutive anagrams
        return result;
    }
}
