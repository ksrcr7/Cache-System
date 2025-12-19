#include "LRUPolicy.h"
#include <stdexcept>

void LRUPolicy::touch_(int key) {
    auto it = pos_.find(key);
    if(it == pos_.end()){
        order_.push_front(key);
        pos_[key] = order_.begin();
        return;
    }
    order_.splice(order_.begin(),order_,it->second);
    it->second = order_.begin();

}

void LRUPolicy::onGet(int key) {
    touch_(key);

}

void LRUPolicy::onPut(int key) {
    touch_(key);

}

int LRUPolicy::evictKey() {
    if(order_.empty()){
        throw std::runtime_error("LRUPolicy::evictKey called on empty policy");
    }
    return order_.back();
}

void LRUPolicy::onErase(int key) {
    auto it = pos_.find(key);
    if(it == pos_.end())return;

    order_.erase(it->second);
    pos_.erase(it);

}
