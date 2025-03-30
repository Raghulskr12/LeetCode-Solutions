class Solution {
    public:
        // Function to check if we can ship all packages within given days using 'capacity'
        int countDaysRequired(int capacity, vector<int>& weights) {
            int daysRequired = 1, currentLoad = 0;
            
            for (int weight : weights) {
            
                // If adding current weight exceeds capacity, start a new day
                if (currentLoad + weight > capacity) {
                    daysRequired++;
                    currentLoad = weight;
                } else {
                    currentLoad += weight;
                }
            }
            
            return daysRequired;
        }
        
        int shipWithinDays(vector<int>& weights, int days) {
            int minCapacity = *max_element(weights.begin(), weights.end()); // Minimum capacity required
            int maxCapacity = accumulate(weights.begin(), weights.end(), 0); // Maximum possible capacity
            
            // Binary search for the optimal capacity
            while (minCapacity <= maxCapacity) {
                int midCapacity = (minCapacity + maxCapacity) / 2;
                int requiredDays = countDaysRequired(midCapacity, weights);
                
                if (requiredDays <= days) {
                    maxCapacity = midCapacity - 1; // Try reducing capacity
                } else {
                    minCapacity = midCapacity + 1; // Increase capacity
                }
            }
            
            return minCapacity;
        }
    };
    