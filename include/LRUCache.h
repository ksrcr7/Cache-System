#ifndef CACHE_SYSTEM_LRUCACHE_H
#define CACHE_SYSTEM_LRUCACHE_H

#include <unordered_map>
#include <list>


class LRUCache{
public:
    LRUCache(int);
    bool get(int,int&);
    void put(int,int);
    int size()const;
    int capacity()const;

private:
    int capacity_;
    using Node = std::pair<int,int>;
    using ListIt = std::list<Node>::iterator;
    std::list<Node> cacheList;
    std::unordered_map<int, ListIt> HashMap;


};





















#endif //CACHE_SYSTEM_LRUCACHE_H
