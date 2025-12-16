#include "LRUCache.h"

bool LRUCache::get(int key, int &outValue) {
    auto find = HashMap.find(key);
    if(find == HashMap.end())
        return false;

    auto it = find->second;
    outValue = it->second;

    cacheList.splice(cacheList.begin(),cacheList,it);
    return true;

}
