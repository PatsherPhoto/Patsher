#ifndef ARRAY_H
#define ARRAY_H

#include <array>



// systems core & class 
#include "core/config/list.h"
#include "core/config/hash_map.h"
#include "core/string/string.h"
#include "core/error/error_list.h"
#include "core/object/ref.h"
#include "core/object/class_db.h"
// Array Class
class Variant;
class ArrayPrivate;
class Object;
class StringName;
class Callbale;

// class Array : Ref class 
class Array : public Ref {
    // 
    mutable ArrayPrivate *p;
    void unref() const; 
    // Array Emum
    enum Math {};
    enum ValueTyped {};
    // Contstructor Array
    Array() = default;
    ~Array() = default;
    explicit Array(int size);
    // void Array to Math 
    void append(const String& value);
    void appendValue(const String& value);
    bool isEmpty() const;
    void size(int size);
    void getSize() const;
    void getArrayList(const List<int>& p_size);
    void getEmpty() const;
    void _ref(const Array& p_from) const;
    void set(int p_index, const Variant& p_value);
    Variant& operator[](int p_indx);
    bool operator==(const Array& p_array);
    bool operator!=(const Array& p_array);
    bool recusive_equale(const Array& p_array, int);
    
    //
    uint32_t hash() const; 
    uint32_t recusive_hash(int p_count) const;
    void operator=(const Array& p_array);
    void assings(const Array& p_array);
    void push_back(const Variant& p_value);
    void append(const Variant& p_value) {push_back(p_value);}
    void append_array(const Array& p_array);
    Error insert(const Array& p_array);





    // 
    private:
        String data;
        int count;
        int call;
    protected:
        static void bind_method();
        static void bind_class();
    

};


#endif // ARRAY_H