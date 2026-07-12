class Node {
public:
    int key, value, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    Node *head, *tail;
    int size;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node *node) {
        Node *p = node->prev;
        Node *n = node->next;

        p->next = n;
        n->prev = p;
        size--;
    }

    Node* removeLast() {
        if (size == 0)
            return nullptr;

        Node *node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache {
private:
    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node *node) {
        int freq = node->freq;

        freqList[freq]->removeNode(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new List();

        freqList[node->freq]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node *node = keyNode[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (keyNode.size() == capacity) {
            Node *node = freqList[minFreq]->removeLast();
            keyNode.erase(node->key);
            delete node;
        }

        Node *newNode = new Node(key, value);

        minFreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->addFront(newNode);
        keyNode[key] = newNode;
    }
};