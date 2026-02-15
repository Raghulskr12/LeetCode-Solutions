class Solution {

    public String removeDuplicateLetters(String inputString) {

        // Stores last occurrence index of each character
        int[] lastOccurrence = new int[26];

        // Tracks whether a character is already in stack
        boolean[] isSeen = new boolean[26];

        // Monotonic stack to build lexicographically smallest result
        Stack<Character> characterStack = new Stack<>();


        // Step 1: Record last occurrence of every character
        for (int i = 0; i < inputString.length(); i++) {
            char currentChar = inputString.charAt(i);
            lastOccurrence[currentChar - 'a'] = i;
        }


        // Step 2: Traverse the string
        for (int i = 0; i < inputString.length(); i++) {

            char currentChar = inputString.charAt(i);

            // If already included → skip
            if (isSeen[currentChar - 'a']) {
                continue;
            }

            /*
             Pop characters while:
             1. Stack not empty
             2. Top char > current char  (to make lexicographically smaller)
             3. Top char appears again later (safe to remove now)
            */
            while (!characterStack.isEmpty() &&
                   characterStack.peek() > currentChar &&
                   lastOccurrence[characterStack.peek() - 'a'] > i) {

                char removedChar = characterStack.pop();
                isSeen[removedChar - 'a'] = false;
            }

            // Push current character
            characterStack.push(currentChar);
            isSeen[currentChar - 'a'] = true;
        }


        // Step 3: Build result string from stack
        StringBuilder result = new StringBuilder();

        for (char ch : characterStack) {
            result.append(ch);
        }

        return result.toString();
    }
}
