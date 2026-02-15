// Doubly Linked List Node
class Node {

    int key;      // Cache key
    int value;    // Cache value

    Node prev;    // Pointer to previous node
    Node next;    // Pointer to next node

    // Dummy node constructor
    Node() {
        this.key = -1;
        this.value = -1;
    }

    // Actual node constructor
    Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}



class LRUCache {

    // HashMap → key → node reference
    private Map<Integer, Node> cacheMap;

    // Maximum capacity of cache
    private int capacity;

    // Dummy head & tail of DLL
    private Node head;
    private Node tail;



    // Constructor → initialize cache
    public LRUCache(int capacity) {

        this.capacity = capacity;
        this.cacheMap = new HashMap<>();

        // Create dummy nodes
        this.head = new Node();
        this.tail = new Node();

        // Connect head <-> tail
        head.next = tail;
        tail.prev = head;
    }



    // Insert node right after head (Most Recently Used position)
    private void insertAfterHead(Node node) {

        Node nextNode = head.next;

        head.next = node;
        node.prev = head;

        node.next = nextNode;
        nextNode.prev = node;
    }



    // Remove a node from DLL
    private void deleteNode(Node node) {

        Node previousNode = node.prev;
        Node nextNode = node.next;

        previousNode.next = nextNode;
        nextNode.prev = previousNode;
    }



    // Get value by key
    public int get(int key) {

        // If key not present → return -1
        if (!cacheMap.containsKey(key)) {
            return -1;
        }

        // Fetch node
        Node node = cacheMap.get(key);

        // Move node to front (recently used)
        deleteNode(node);
        insertAfterHead(node);

        return node.value;
    }



    // Insert / Update key-value
    public void put(int key, int value) {

        // Case 1: Key already exists → update + move to front
        if (cacheMap.containsKey(key)) {

            Node existingNode = cacheMap.get(key);

            existingNode.value = value;

            deleteNode(existingNode);
            insertAfterHead(existingNode);
        }

        // Case 2: New key
        else {

            // If cache is full → remove LRU node
            if (cacheMap.size() == capacity) {

                Node lruNode = tail.prev;

                deleteNode(lruNode);
                cacheMap.remove(lruNode.key);
            }

            // Insert new node at front
            Node newNode = new Node(key, value);

            insertAfterHead(newNode);
            cacheMap.put(key, newNode);
        }
    }
}
