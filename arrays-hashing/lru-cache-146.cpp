class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    unordered_map<int, Node*> mp;
    int capacity;

    Node* head;
    Node* tail;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void moveToFront(Node* node) {
        remove(node);
        addToFront(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;

        Node* node = mp[key];
        moveToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            node->val = value;
            moveToFront(node);
            return;
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        addToFront(node);

        if (mp.size() > capacity) {
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */