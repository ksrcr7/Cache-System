#include "LRUCache.h"
#include <stdexcept>

bool LRUCache::get(int key, int &outValue) {
    auto find = HashMap.find(key);
    if(find == HashMap.end())
        return false;

    auto it = find->second;
    outValue = it->second;

    cacheList.splice(cacheList.begin(),cacheList,it);
    return true;

}

LRUCache::LRUCache(int capacity) {
    if(capacity <= 0){
        throw std::invalid_argument("Capacity must be at least 1.");
    }
    capacity_ = capacity;

}

void LRUCache::put(int key, int value) {
    auto it = HashMap.find(key);
    if(it != HashMap.end()){
        auto update = it->second;
        update->second = value;
        cacheList.splice(cacheList.begin(),cacheList,update);
        return;
    }
    if(cacheList.size() == capacity_){
        int oldKey = cacheList.back().first;
        HashMap.erase(oldKey);
        cacheList.pop_back();
    }

    cacheList.emplace_front(key,value);
    HashMap[key] = cacheList.begin();

}

int LRUCache::size() const {
    return cacheList.size();
}

int LRUCache::capacity() const {
    return capacity_;
}
