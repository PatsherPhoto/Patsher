#ifndef REF_H
#define REF_H

#include "core/config/hash_map.h"
#include "core/config/list.h"
#include "core/string/string.h"
#include "core/object/class_db.h"
#include "core/math/array.h"
#include "core/object/object.h"

class RefManager;

template <typename T> 
class Ref {
    GGClass(Ref, RefManager);
    // 
    public:
        enum RefType {
            REF_FLOAT,
            REF_INT,
            REF_INIT,
            REF_VECTOR
        };
        enum RefApi {
            REF_NODE,
            RFF_MODEL,
            REF_API
        };
        struct RefConted {
            T* ptr;
            int counted;
            int weak;
            
            explicit RefConted(T* ptr) : prt(prt), counted(1), weak(0) {} 
        };

        RefConted* refcount;

        Ref();
        explicit Ref(T* ptr);
        Ref(const Ref& p_ref);
        Ref& operator=(const Ref& p_ref);

        T* get() const;
        void rest(T* ptr);
        T& operator*() const;
        T& operator->() const;
        bool operator==(const Ref& p_ref);
        bool operator!=(const Ref& p_ref);
        int getCountedCount();
        int getWeakCount();
        void throwError(const Error& p_null);

        Ref<T> weakRef() const;
        void ToRef();
        bool isNull();
        bool isCountedRef();
        bool isWeakRef();

        // new Ref Func values 
        void append(const Ref<T> p_ref);
        void append(const T& p_value);

        // other void
        void getRefList(const List<String> p_ref, const List<bool> p_ref_name);
        void getRef(const String& p_ref);
        void update(float delta);
        bool updated();
        void RefMaper();
        void addChild(const Array& child);
        void getChildern() const;
        void getChildrenByName(const String& p_name);
    protected:
        static void bind_methods();
        static void bind_class();
    private:
        Ref(); // constructor   
        String ref;
    //     
};

#endif // REF_H