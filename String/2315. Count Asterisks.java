class Solution {
    public int countAsterisks(String s) {

        int asteriskCount = 0;     // Counts valid '*' characters
        int pipeCount = 0;         // Counts '|' seen so far

        // Traverse each character in the string
        for (int i = 0; i < s.length(); i++) {

            char currentChar = s.charAt(i);

            // If we encounter a pipe, increment pipeCount
            if (currentChar == '|') {
                pipeCount++;
            }

            /*
             * If pipeCount is even, we are OUTSIDE a pair of pipes
             * If pipeCount is odd, we are INSIDE pipes
             */
            if (pipeCount % 2 == 0) {
                // Count '*' only when outside pipes
                if (currentChar == '*') {
                    asteriskCount++;
                }
            }
        }

        return asteriskCount;
    }
}
