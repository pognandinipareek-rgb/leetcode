class AllOne {

    // A bucket: all keys inside have exactly the same count
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;

        Node(int count) : count(count), prev(nullptr), next(nullptr) {}

        // Insert newNode right after "this" and return it
        Node* insertAfter(Node* newNode) {
            newNode->prev = this;
            newNode->next = this->next;
            this->next->prev = newNode;
            this->next = newNode;
            return newNode;
        }

        // Unlink "this" from the list
        void remove() {
            this->prev->next = this->next;
            this->next->prev = this->prev;
        }
    };

    Node* head;                              // dummy, smaller than any real count
    Node* tail;                              // dummy, larger than any real count
    unordered_map<string, Node*> keyToNode;  // key -> bucket it lives in

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    ~AllOne() {
        Node* node = head;
        while (node != nullptr) {
            Node* nxt = node->next;
            delete node;
            node = nxt;
        }
    }

    void inc(string key) {
        auto it = keyToNode.find(key);

        if (it == keyToNode.end()) {
            // New key -> goes to count 1
            Node* target = head->next;
            if (target == tail || target->count > 1) {
                target = head->insertAfter(new Node(1));
            }
            target->keys.insert(key);
            keyToNode[key] = target;
        } else {
            // Existing key -> move to count + 1
            Node* curr = it->second;
            int nextCount = curr->count + 1;
            Node* target = curr->next;
            if (target == tail || target->count != nextCount) {
                target = curr->insertAfter(new Node(nextCount));
            }
            target->keys.insert(key);
            keyToNode[key] = target;

            curr->keys.erase(key);
            if (curr->keys.empty()) {
                curr->remove();
                delete curr;   // C++ has no GC, free the empty bucket
            }
        }
    }

    void dec(string key) {
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()) return;

        Node* curr = it->second;
        curr->keys.erase(key);

        if (curr->count == 1) {
            // Count would hit 0 -> forget the key
            keyToNode.erase(key);
        } else {
            // Move to count - 1
            int prevCount = curr->count - 1;
            Node* target = curr->prev;
            if (target == head || target->count != prevCount) {
                target = target->insertAfter(new Node(prevCount));
            }
            target->keys.insert(key);
            keyToNode[key] = target;
        }

        if (curr->keys.empty()) {
            curr->remove();
            delete curr;       // C++ has no GC, free the empty bucket
        }
    }

    string getMaxKey() {
        return tail->prev == head ? "" : *(tail->prev->keys.begin());
    }

    string getMinKey() {
        return head->next == tail ? "" : *(head->next->keys.begin());
    }
};