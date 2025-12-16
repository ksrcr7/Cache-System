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
