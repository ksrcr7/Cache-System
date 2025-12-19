

#ifndef CACHE_SYSTEM_LRUPOLICY_H
#define CACHE_SYSTEM_LRUPOLICY_H
#include "IEvictionPolicy.h"
#include <list>
#include <unordered_map>

class LRUPolicy : public IEvictionPolicy {
public:
    void onGet(int key) override;
    void onPut(int key) override;
    int evictKey() override;
    void onErase(int key) override;

private:
    using ListIt = std::list<int>::iterator;
    void touch_(int key);
    std::list<int> order_;
    std::unordered_map<int,ListIt> pos_;


};
























#endif //CACHE_SYSTEM_LRUPOLICY_H
