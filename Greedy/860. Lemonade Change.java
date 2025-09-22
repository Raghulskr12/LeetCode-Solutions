class Solution {
    public boolean lemonadeChange(int[] customerBills) {
        int fiveDollarCount = 0;  // Count of $5 bills in hand
        int tenDollarCount = 0;   // Count of $10 bills in hand

        // Iterate through each customer's bill
        for (int bill : customerBills) {
            if (bill == 5) {
                // Customer pays with $5, no change needed
                fiveDollarCount++;
            } 
            else if (bill == 10) {
                // Customer pays with $10, give back one $5 if available
                if (fiveDollarCount > 0) {
                    fiveDollarCount--;
                    tenDollarCount++;
                } else {
                    // Can't give $5 change
                    return false;
                }
            } 
            else { 
                // Customer pays with $20
                // Prefer to give one $10 and one $5 as change if possible
                if (tenDollarCount > 0 && fiveDollarCount > 0) {
                    tenDollarCount--;
                    fiveDollarCount--;
                }
                // Otherwise, give three $5 bills as change
                else if (fiveDollarCount >= 3) {
                    fiveDollarCount -= 3;
                } 
                else {
                    // Can't provide change
                    return false;
                }
            }
        }

        // All customers received correct change
        return true;
    }
}
