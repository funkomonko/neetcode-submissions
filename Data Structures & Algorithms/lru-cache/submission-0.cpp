class LRUCache {
public:
    unordered_map <int, list<pair<int ,int>>::iterator> lruCache;
    list <pair<int,int>> timeStamp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(lruCache.contains(key)){
            int temp = lruCache[key]->second;
            timeStamp.erase(lruCache[key]);
            timeStamp.push_front({key, temp});
            lruCache[key] = timeStamp.begin();
            return lruCache[key]->second;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(get(key) == -1){
            timeStamp.push_front({key, value});
            auto tempptr = timeStamp.begin();
            lruCache[key] = tempptr;
            
            if(timeStamp.size() > cap){
                lruCache.erase(timeStamp.back().first);
                timeStamp.pop_back();
            }
        }
        else{
            timeStamp.erase(lruCache[key]);
            timeStamp.push_front({key, value});
            
            lruCache[key] = timeStamp.begin();
        }
    }
};
