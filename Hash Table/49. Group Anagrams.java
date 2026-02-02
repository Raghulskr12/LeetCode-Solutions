class Solution {
    public List<List<String>> groupAnagrams(String[] words) {

        // Map to store grouped anagrams
        // Key   → sorted version of the word
        // Value → list of original words that are anagrams
        Map<String, List<String>> anagramMap = new HashMap<>();

        // Traverse each word in the input array
        for (String word : words) {

            // Convert word to character array
            char[] characters = word.toCharArray();

            // Sort characters to form the anagram key
            Arrays.sort(characters);

            // Convert sorted characters back to string
            String sortedKey = new String(characters);

            // If this anagram group doesn't exist, create it
            if (!anagramMap.containsKey(sortedKey)) {
                anagramMap.put(sortedKey, new ArrayList<>());
            }

            // Add the original word to its anagram group
            anagramMap.get(sortedKey).add(word);
        }

        // Return all grouped anagrams as a list
        return new ArrayList<>(anagramMap.values());
    }
}
