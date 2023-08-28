#ifndef MAP_H
#define MAP_H
/**
 * @class Map
*/
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "core/object/class_db.h"
#include "core/object/object.h"


template <class T>
class Map {
    public:
        void store_map();
        Map();
        ~Map();
    protected:
        static void bind_method();
        static void rigister_class();
    private:
        //
};



#endif // MAP_H