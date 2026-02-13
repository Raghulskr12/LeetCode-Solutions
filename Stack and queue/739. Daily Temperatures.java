class Solution {

    public int[] dailyTemperatures(int[] temperatures) {

        // Result array:
        // answer[i] = number of days to wait for a warmer temperature
        int[] answer = new int[temperatures.length];

        // By default Java fills with 0, but keeping for clarity
        Arrays.fill(answer, 0);

        // Stack will store INDICES (not temperatures)
        // It maintains a decreasing temperature stack
        Stack<Integer> indexStack = new Stack<>();

        // Traverse all days
        for (int currentDay = 0; currentDay < temperatures.length; currentDay++) {

            /*
             While:
             - Stack not empty
             - Current temperature is warmer than stack top day
             
             Then we found the "next warmer day"
            */
            while (!indexStack.isEmpty() &&
                   temperatures[indexStack.peek()] < temperatures[currentDay]) {

                // Get the previous colder day's index
                int previousDay = indexStack.pop();

                // Distance between days = answer
                answer[previousDay] = currentDay - previousDay;
            }

            // Push current day index to stack
            indexStack.push(currentDay);
        }

        return answer;
    }
}
