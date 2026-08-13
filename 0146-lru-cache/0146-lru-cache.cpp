class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    unordered_map<int, Node*> m;
    int limit;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(Node* newNode) {       // O(1)

        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode) {       // O(1)

        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];

        // Make this node recently used
        delNode(ansNode);
        addNode(ansNode);

        return ansNode->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (m.find(key) != m.end()) {

            Node* oldNode = m[key];

            delNode(oldNode);
            delete oldNode;

            m.erase(key);
        }

        // Cache is full
        if (m.size() == limit) {

            Node* lruNode = tail->prev;

            delNode(lruNode);

            m.erase(lruNode->key);

            delete lruNode;
        }

        // Add new node
        Node* newNode = new Node(key, value);

        addNode(newNode);

        m[key] = newNode;
    }
};