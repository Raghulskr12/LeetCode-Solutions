class Solution {
    public int[] asteroidCollision(int[] nums) {

        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < nums.length; i++) {

            if (s.empty() || nums[i] > 0) {
                s.push(nums[i]);
            } 
            else { // nums[i] < 0

                boolean destroyed = false;

                while (!s.empty() && s.peek() > 0) {

                    if (s.peek() < Math.abs(nums[i])) {
                        s.pop();          // stack top destroyed
                    }
                    else if (s.peek() == Math.abs(nums[i])) {
                        s.pop();          // both destroyed
                        destroyed = true;
                        break;
                    }
                    else {
                        destroyed = true; // current destroyed
                        break;
                    }
                }

                if (!destroyed) {
                    s.push(nums[i]);
                }
            }
        }

        int[] ans = new int[s.size()];
        for (int i = ans.length - 1; i >= 0; i--) {
            ans[i] = s.pop();
        }

        return ans;
    }
}
