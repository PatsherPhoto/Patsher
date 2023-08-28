#ifndef ERROR_LIST_H
#define ERROR_LIST_H


#include "core/config/engine.h"
#include "core/config/hash_map.h"
#include "core/config/list.h"
#include "core/object/class_db.h"
#include "core/string/string.h"
#include "core/object/ref.h"

class Error;
// Error List 
class ErrorList : public Ref {
    public:
        //
        enum Error {

        };
    protected:
        //
        static void bind_method();
};


#endif