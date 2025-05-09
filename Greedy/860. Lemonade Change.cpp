class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int fiveDollarCount = 0;  // Count of $5 bills
            int tenDollarCount = 0;   // Count of $10 bills
    
            for (int i = 0; i < bills.size(); i++) {
                if (bills[i] == 5) {
                    // Customer pays with $5, no change needed
                    fiveDollarCount++;
                }
                else if (bills[i] == 10) {
                    // Customer pays with $10, needs $5 as change
                    if (fiveDollarCount > 0) {
                        fiveDollarCount--;
                        tenDollarCount++;
                    } else {
                        // No $5 bill to give as change
                        return false;
                    }
                }
                else if (bills[i] == 20) {
                    // Customer pays with $20, needs $15 as change
                    if (tenDollarCount > 0 && fiveDollarCount > 0) {
                        // Prefer giving one $10 and one $5 as change
                        tenDollarCount--;
                        fiveDollarCount--;
                    } else if (fiveDollarCount >= 3) {
                        // Otherwise give three $5 bills
                        fiveDollarCount -= 3;
                    } else {
                        // Not enough change available
                        return false;
                    }
                }
            }
    
            return true; // Successfully gave change to all customers
        }
    };
    