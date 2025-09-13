class Solution {
    public boolean vowel(char a) {
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }

    public int maxFreqSum(String s) {
        Map<Character, Integer> vow = new HashMap<>();
        Map<Character, Integer> con = new HashMap<>();

        for (char a : s.toCharArray()) {
            if (vowel(a)) {
                vow.put(a, vow.getOrDefault(a, 0) + 1);
            } else {
                con.put(a, con.getOrDefault(a, 0) + 1);
            }
        }

        // Find max frequency among vowels
        int maxVowel = vow.isEmpty() ? 0 :
                Collections.max(vow.values());

        // Find max frequency among consonants
        int maxCon = con.isEmpty() ? 0 :
                Collections.max(con.values());

        // Return sum of max vowel + max consonant freq
        return maxVowel + maxCon;
    }
}