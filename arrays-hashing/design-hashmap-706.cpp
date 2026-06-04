class MyHashMap {
    private:
        struct Node {
            int key;
            int value;
            Node(int k, int v) : key(k), value(v) {}
        };
    
        static const int BUCKET_SIZE = 769;
        std::vector<std::list<Node>> buckets;
    
        int getHash(int key) {
            return key % BUCKET_SIZE;
        }
    
    public:
        MyHashMap() {
            buckets.resize(BUCKET_SIZE);
        }
        
        void put(int key, int value) {
            int index = getHash(key);
            auto& bucket = buckets[index];
            
            for (auto& node : bucket) {
                if (node.key == key) {
                    node.value = value;
                    return;
                }
            }
            bucket.push_back(Node(key, value));
        }
        
        int get(int key) {
            int index = getHash(key);
            auto& bucket = buckets[index];
            
            for (const auto& node : bucket) {
                if (node.key == key) {
                    return node.value; // Key found
                }
            }
            return -1;
        }
        
        void remove(int key) {
            int index = getHash(key);
            auto& bucket = buckets[index];
            
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (it->key == key) {
                    bucket.erase(it); // Key found, delete it
                    return;
                }
            }
        }
    };
    
    /**
     * Your MyHashMap object will be instantiated and called as such:
     * MyHashMap* obj = new MyHashMap();
     * obj->put(key,value);
     * int param_2 = obj->get(key);
     * obj->remove(key);
     */