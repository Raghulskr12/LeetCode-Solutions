#include <bits/stdc++.h>
using namespace std;

// Node class represents a single element in the linked list
class Node {
public:
    int data;       // Holds the value of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to convert a vector of integers into a linked list
Node* arrayToLinkedList(const vector<int>& inputArray, int size) {
    if (size == 0) return nullptr; // Return null if the array is empty

    // Create the head node
    Node* head = new Node(inputArray[0]);
    Node* current = head;

    // Add remaining elements as nodes
    for (int i = 1; i < size; i++) {
        current->next = new Node(inputArray[i]);
        current = current->next;
    }

    return head; // Return the head of the linked list
}

// Function to print all elements of the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Function to count and print the number of nodes in the linked list
void countNodes(Node* head) {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    cout << "Total nodes: " << count << endl;
}

// Function to search for a target value in the linked list
void findTarget(Node* head, int target) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == target) {
            cout << "Target " << target << " found in the list." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Target " << target << " not found in the list." << endl;
}

// Main function
int main() {
    vector<int> inputArray = {1, 2, 3, 4};

    // Convert array to linked list
    Node* head = arrayToLinkedList(inputArray, inputArray.size());

    // Print the linked list
    printLinkedList(head);

    // Count number of nodes in the list
    countNodes(head);

    // Search for a target value in the list
    int target = 6;
    findTarget(head, target);

    return 0;
}
