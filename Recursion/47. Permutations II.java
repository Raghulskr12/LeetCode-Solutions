class Solution {

    /**
     * Backtracking function to generate unique permutations
     *
     * @param result   -> Stores all unique permutations
     * @param current  -> Current permutation being built
     * @param nums     -> Sorted input array
     * @param used     -> Tracks visited elements
     */
    public void generateUniquePermutations(List<List<Integer>> result,
                                           List<Integer> current,
                                           int[] nums,
                                           boolean[] used) {

        // 🔹 Base Case:
        // If permutation length == array length → store it
        if (current.size() == nums.length) {
            result.add(new ArrayList<>(current));
            return;
        }

        // 🔹 Explore all elements
        for (int i = 0; i < nums.length; i++) {

            // Skip already used elements
            if (used[i]) continue;

            /**
             * 🔹 Duplicate Skipping Logic
             *
             * Condition explanation:
             * nums[i] == nums[i-1] → duplicate number
             * !used[i-1]           → previous duplicate not used in this branch
             *
             * So picking nums[i] would create duplicate permutation.
             */
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            // Choose element
            current.add(nums[i]);
            used[i] = true;

            // Explore deeper
            generateUniquePermutations(result, current, nums, used);

            // 🔹 Backtrack
            current.remove(current.size() - 1);
            used[i] = false;
        }
    }


    /**
     * Main function — returns all unique permutations
     */
    public List<List<Integer>> permuteUnique(int[] nums) {

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();

        // 🔹 Sort required for duplicate handling
        Arrays.sort(nums);

        boolean[] used = new boolean[nums.length];

        generateUniquePermutations(result, current, nums, used);

        return result;
    }
}
