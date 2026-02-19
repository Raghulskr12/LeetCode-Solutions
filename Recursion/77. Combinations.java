class Solution {
    public void generateCombinations(int n,
                                     int k,
                                     int start,
                                     List<List<Integer>> result,
                                     List<Integer> current) {

        // 🔹 Base Case:
        // If current combination size becomes k → store it
        if (current.size() == k) {
            result.add(new ArrayList<>(current)); // deep copy
            return;
        }

        // 🔹 Try picking numbers from 'start' to 'n'
        for (int num = start; num <= n; num++) {

            // Choose the current number
            current.add(num);

            // Explore further with next numbers
            generateCombinations(n, k, num + 1, result, current);

            // Backtrack → remove last added number
            current.remove(current.size() - 1);
        }
    }


    /**
     * Main function called by LeetCode
     * Returns all possible combinations of size k from 1..n
     */
    public List<List<Integer>> combine(int n, int k) {

        List<List<Integer>> result = new ArrayList<>(); // stores final answer
        List<Integer> current = new ArrayList<>();      // temporary combination

        // Start backtracking from number 1
        generateCombinations(n, k, 1, result, current);

        return result;
    }
}
