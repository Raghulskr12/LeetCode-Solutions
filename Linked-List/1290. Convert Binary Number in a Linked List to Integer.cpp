class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string binaryStr = "";
        ListNode* temp = head;

        // Build binary string from the list
        while (temp) {
            binaryStr += to_string(temp->val);
            temp = temp->next;
        }

        int result = 0;
        int power = 0;

        // Convert binary string to decimal
        for (int i = binaryStr.size() - 1; i >= 0; i--) {
            if (binaryStr[i] == '1') {
                result += pow(2, power);
            }
            power++;
        }

        return result;
    }
};
