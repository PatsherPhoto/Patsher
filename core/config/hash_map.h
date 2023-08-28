#ifndef HASH_MAP_H
#define HASH_MAP_H
/**
 * @class HasMap
*/

#include "list.h"
#include "core/math/array.h"
#include "core/string/string.h"




class HashList;
template <typename T>
class HashMap {
   HashMap();
   ~HashMap();
   public:
    void insert(int key, const String& p_value);
    void deleted(int key);
    void get(int key);
    void set(const String& p_value);
    struct Entry {
        Tkey p_key,
        TValue p_value;
        Entry(const Tkey& k, const TValue& v) : p_key(k), p_value(v) {}
    };
};



#endif // HASH_MAP_H