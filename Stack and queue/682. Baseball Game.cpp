class Solution {
    public:
        int calPoints(vector<string>& operations) {
            stack<int> scoreStack; // Stack to store valid scores
            int totalScore = 0;    // Final score accumulator
    
            for (int i = 0; i < operations.size(); i++) {
                string currentOp = operations[i]; // Current operation or score
    
                if (currentOp == "C") {
                    // Cancel the previous valid score
                    scoreStack.pop();
                }
                else if (currentOp == "D") {
                    // Double the previous score and add it
                    int lastScore = scoreStack.top();
                    int doubledScore = lastScore * 2;
                    scoreStack.push(doubledScore);
                }
                else if (currentOp == "+") {
                    // Add the last two valid scores
                    int topScore = scoreStack.top();
                    scoreStack.pop();
                    int secondTopScore = scoreStack.top();
                    int sumScore = topScore + secondTopScore;
    
                    scoreStack.push(topScore); // Re-push the popped top score
                    scoreStack.push(sumScore); // Push the calculated sum
                }
                else {
                    // It's a valid numeric score
                    scoreStack.push(stoi(currentOp)); // Convert string to int and push
                }
            }
    
            // Sum all valid scores remaining in the stack
            while (!scoreStack.empty()) {
                totalScore += scoreStack.top();
                scoreStack.pop();
            }
    
            return totalScore;
        }
    };
    