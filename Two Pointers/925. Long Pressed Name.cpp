class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nameLen = name.size();    // Length of the 'name' string
        int typedLen = typed.size();  // Length of the 'typed' string

        int nameIndex = 0;  // Pointer for 'name'
        int typedIndex = 0; // Pointer for 'typed'

        // Traverse the 'typed' string
        while (typedIndex < typedLen) {
            if (nameIndex < nameLen && name[nameIndex] == typed[typedIndex]) {
                // Characters match, move both pointers
                nameIndex++;
                typedIndex++;
            } else if (typedIndex > 0 && typed[typedIndex] == typed[typedIndex - 1]) {
                // Current character in 'typed' is a repetition (long press)
                typedIndex++;
            } else {
                // Character doesn't match and isn't a valid repetition
                return false;
            }
        }

        // After traversing, all characters in 'name' should be matched
        return nameIndex == nameLen;
    }
};
