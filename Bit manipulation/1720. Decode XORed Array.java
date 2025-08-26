class Solution {
    public int[] decode(int[] encoded, int first) {
        // Create the original array with size = encoded.length + 1
        int[] decoded = new int[encoded.length + 1];

        // The first element of the decoded array is given
        decoded[0] = first;

        // Each next element can be found using XOR relation:
        // decoded[i + 1] = decoded[i] ^ encoded[i]
        for (int i = 0; i < encoded.length; i++) {
            decoded[i + 1] = decoded[i] ^ encoded[i];
        }

        // Return the fully decoded array
        return decoded;
    }
}
