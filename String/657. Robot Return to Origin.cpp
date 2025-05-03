class Solution {
    public:
        bool judgeCircle(string moves) {
            int vertical = 0;  // Tracks vertical movement: 'U' increases, 'D' decreases
            int horizontal = 0;  // Tracks horizontal movement: 'R' increases, 'L' decreases
    
            for(int i = 0; i < moves.size(); i++)
            {
                if(moves[i] == 'U') vertical += 1;     // Move up
                if(moves[i] == 'D') vertical -= 1;     // Move down
                if(moves[i] == 'R') horizontal += 2;   // Move right
                if(moves[i] == 'L') horizontal -= 2;   // Move left
            }
    
            // If both vertical and horizontal movements are balanced, return to origin
            if(vertical == 0 && horizontal == 0) 
                return true;
    
            return false;
        }
    };
    