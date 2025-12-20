#include "LRUCache.h"
#include "LRUPolicy.h"
#include <stdexcept>

bool LRUCache::get(int key, int &outValue) {
    auto it = storage.find(key);
    if(it != storage.end()){
        outValue = it->second;
        policy_->onGet(key);
        return true;
    }
    return false;

}

LRUCache::LRUCache(int capacity) {
    if(capacity <= 0){
        throw std::invalid_argument("Capacity must be at least 1.");
    }
    capacity_ = capacity;
    policy_ = std::make_unique<LRUPolicy>();

}

void LRUCache::put(int key, int value) {
    auto it  = storage.find(key);
    if(it != storage.end()){
        storage[key] = value;
        policy_->onPut(key);
    }
    if(storage.size() == capacity_){
        int victim = policy_->evictKey();
        storage.erase(victim);
        policy_->onErase(victim);

    }
    storage.emplace(key,value);
    policy_->onPut(key);

}

int LRUCache::size() const {
    return storage.size();
}

int LRUCache::capacity() const {
    return capacity_;
}

bool LRUCache::erase(int key) {
    auto it = storage.find(key);
    if(it != storage.end()){
        storage.erase(it);
        policy_->onErase(key);
        return true;
    }
    return false;
}
