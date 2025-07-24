#include <bits/stdc++.h>
using namespace std;

// Definition of a Node in the singly linked list
class Node {
public:
    int data;       // Holds the value of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize node with data
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to convert a vector of integers into a linked list
Node* arrayToLinkedList(vector<int> inputArray, int size) {
    if (size == 0) return nullptr; // Return null if array is empty

    // Create the head node using the first element
    Node* head = new Node(inputArray[0]);
    Node* current = head;

    // Loop through the remaining elements and create nodes
    for (int i = 1; i < size; i++) {
        current->next = new Node(inputArray[i]); // Link new node
        current = current->next; // Move to the newly created node
    }

    return head; // Return the head of the linked list
}

// Function to print all elements in the linked list
void printLinkedList(Node* head) {
    Node* current = head;

    // Traverse and print the list
    while (current != nullptr) {
        cout << current->data << "->";
        current = current->next;
    }

    cout << "nullptr"; // Indicate the end of the list
}

int main() {
    // Input array
    vector<int> inputArray = {1, 2, 3, 4};

    // Convert the array to a linked list
    Node* linkedListHead = arrayToLinkedList(inputArray, inputArray.size());

    // Print the linked list
    printLinkedList(linkedListHead);

    return 0;
}
