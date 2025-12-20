#ifndef CACHE_SYSTEM_LRUCACHE_H
#define CACHE_SYSTEM_LRUCACHE_H

#include "IEvictionPolicy.h"
#include <unordered_map>
#include <memory>


class LRUCache{
public:
    explicit LRUCache(int);
    bool get(int,int&);
    void put(int,int);
    int size()const;
    int capacity()const;

private:
    int capacity_;
    std::unordered_map<int,int> storage;
    std::unique_ptr<IEvictionPolicy> policy_;


};





















#endif //CACHE_SYSTEM_LRUCACHE_H
