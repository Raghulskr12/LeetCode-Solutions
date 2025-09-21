class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        // Sort both arrays to match weakest players with least capable trainers first
        Arrays.sort(players);
        Arrays.sort(trainers);

        int playerIndex = 0;    // Pointer for players
        int trainerIndex = 0;   // Pointer for trainers
        int matchedCount = 0;   // Number of successful matches

        // Iterate through players and trainers
        while(playerIndex < players.length && trainerIndex < trainers.length) {
            // If the current trainer can train the current player
            if(trainers[trainerIndex] >= players[playerIndex]) {
                playerIndex++;     // Move to next player
                trainerIndex++;    // Move to next trainer
                matchedCount++;    // Increment matched count
            } else {
                trainerIndex++;    // Trainer too weak, try next trainer
            }
        }

        return matchedCount;
    }
}
