#ifndef CACHE_SYSTEM_IEVICTIONPOLICY_H
#define CACHE_SYSTEM_IEVICTIONPOLICY_H


class IEvictionPolicy{
public:
    virtual ~IEvictionPolicy() = default;
    virtual void onGet(int key)=0;
    virtual void onPut(int key)=0;
    virtual int evictKey()=0;
    virtual void onErase(int key)=0;

};


















#endif //CACHE_SYSTEM_IEVICTIONPOLICY_H
