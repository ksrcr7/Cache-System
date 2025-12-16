API: put(key,value) -> Enter:(int key,int value), Return:void
if key exists -> update value and that key becomes the MRU of value.

MRU = Most recently used.
LRU = Least recently used.

task: save/update + if capacity was full -> delete LRU (eviction).
get(key,outValue) -> bool (if key does not exist -> return false and outValue is unchanged)
size(): How many items exist in Cache?
capacity():Maximum number of items that can be stored
I selected this template because it is simple at first for testing and understanding.
it can be modified or changed in future and next versions.