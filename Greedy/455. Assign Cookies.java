class Solution {
    public int findContentChildren(int[] greedFactors, int[] cookieSizes) {
        // Sort the arrays so we can assign smallest cookies to least greedy children first
        Arrays.sort(cookieSizes);
        Arrays.sort(greedFactors);

        int childIndex = 0;  // Pointer for children
        int cookieIndex = 0; // Pointer for cookies
        int satisfiedChildren = 0; // Count of children who got cookies

        // If there are no cookies, return 0
        if(cookieSizes.length == 0) return 0;

        // Iterate through children and cookies
        while(childIndex < greedFactors.length && cookieIndex < cookieSizes.length) {
            // If the current cookie can satisfy the current child
            if(cookieSizes[cookieIndex] >= greedFactors[childIndex]) {
                childIndex++;       // Move to next child
                satisfiedChildren++; // Increment satisfied children count
            }
            cookieIndex++; // Move to next cookie regardless of satisfaction
        }

        return satisfiedChildren;
    }
}
