class Solution {

    public boolean check(int[] nums, int mid, int k) {

        int parts = 1;
        int sum = 0;

        for (int num : nums) {

            if (sum + num <= mid) {
                sum += num;
            } else {
                parts++;
                sum = num;
            }
        }

        return parts <= k;
    }

    public int splitArray(int[] nums, int k) {

        int low = 0, high = 0;

        for (int num : nums) {
            low = Math.max(low, num);
            high += num;
        }

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(nums, mid, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}
