class Solution {

    /**
     * Backtracking DFS function to generate permutations
     *
     * @param result      -> Stores all permutations
     * @param current     -> Current permutation being built
     * @param nums        -> Input array
     * @param used        -> Tracks which elements are already used
     */
    public void generatePermutations(List<List<Integer>> result,
                                     List<Integer> current,
                                     int[] nums,
                                     boolean[] used) {

        // 🔹 Base Case:
        // If current permutation size equals array length → store it
        if (current.size() == nums.length) {
            result.add(new ArrayList<>(current)); // deep copy
            return;
        }

        // 🔹 Try picking each element
        for (int i = 0; i < nums.length; i++) {

            // Skip if element already used in current permutation
            if (used[i]) continue;

            // Choose element
            current.add(nums[i]);
            used[i] = true;

            // Explore further
            generatePermutations(result, current, nums, used);

            // 🔹 Backtrack
            // Remove last element & mark unused
            current.remove(current.size() - 1);
            used[i] = false;
        }
    }


    /**
     * Main function — returns all permutations
     */
    public List<List<Integer>> permute(int[] nums) {

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();

        // Tracks visited elements
        boolean[] used = new boolean[nums.length];

        // Start DFS
        generatePermutations(result, current, nums, used);

        return result;
    }
}
