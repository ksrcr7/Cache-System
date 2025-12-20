#include "LRUCache.h"
#include <gtest/gtest.h>

TEST(SmokeTest,Basic){
    LRUCache cache(2);
    int v = 0;
    EXPECT_FALSE(cache.get(1,v));
}

TEST(LRUCacheTest,PutandGet){
    LRUCache cache(2);
    int v = 0;
    cache.put(1,10);
    EXPECT_TRUE(cache.get(1,v));
    EXPECT_EQ(v,10);
}

TEST(LRUCacheTest,EvictsLeastRecentlyUsed){
    LRUCache cache(2);
    int v = 0;

    cache.put(1,10);
    cache.put(2,20);
    cache.put(3,30);

    EXPECT_FALSE(cache.get(1,v));
    EXPECT_TRUE(cache.get(2,v));
    EXPECT_TRUE(cache.get(3,v));
}

TEST(LRUCacheTest,UpdateExistingKey){
    LRUCache cache(2);
    int v = 0;
    cache.put(1,100);
    cache.put(1,20);
    EXPECT_TRUE(cache.get(1,v));
    EXPECT_EQ(v,20);
}

TEST(LRUCacheTest,GetMakesKeyMRU){
    LRUCache cache(2);
    int v = 0;

    cache.put(1, 10);
    cache.put(2, 20);

    cache.get(1, v);
    cache.put(3, 30);

    EXPECT_FALSE(cache.get(2, v));
    EXPECT_TRUE(cache.get(1, v));
    EXPECT_TRUE(cache.get(3, v));
}

TEST(LRUCacheTest,Erase){
    LRUCache cache(2);
    int v = 0;
    cache.put(1,10);
    cache.put(2,20);
    cache.get(1,v);
    cache.erase(1);
    cache.put(3,30);

    EXPECT_FALSE(cache.get(1,v));
    EXPECT_TRUE(cache.get(2,v));
    EXPECT_TRUE(cache.get(3,v));
}
