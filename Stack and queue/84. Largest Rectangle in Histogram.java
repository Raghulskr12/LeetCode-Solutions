class Solution {
    public int largestRectangleArea(int[] heights) {

        Stack<Integer> freq = new Stack<>();
        int max = 0;

        for(int i = 0; i < heights.length; i++) {

            while(!freq.isEmpty() && heights[freq.peek()] > heights[i]) {

                int num = freq.pop();   // index of height

                int nse = i;
                int pse = freq.isEmpty() ? -1 : freq.peek();

                int width = nse - pse - 1;
                int area = heights[num] * width;

                max = Math.max(max, area);
            }

            freq.push(i);
        }

        // Remaining bars
        while(!freq.isEmpty()) {

            int num = freq.pop();

            int nse = heights.length;
            int pse = freq.isEmpty() ? -1 : freq.peek();

            int width = nse - pse - 1;
            int area = heights[num] * width;

            max = Math.max(max, area);
        }

        return max;
    }
}
