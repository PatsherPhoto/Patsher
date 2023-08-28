#ifndef ARRAY_STRING_H
#define ARRAY_STRING_H


#include "core/config/list.h"
#include "core/object/class_db.h"
#include "core/object/object.h"
#include "core/string/string.h"
#include "core/object/ref.h"
#include "array.h"

#include <algorithm>
template <typename T>
class Vector;



class TypedArray;
template <typename T>
class ArrayString {
    GGClass(ArrayString, TypedArray);
    // enum of  the array string
    enum Type {
        ARRAY_STR
        ARRAY_LIST,
        ARRAY_ALORIGITM
    };
    struct Typed {
        int count;
        int size;
        String value;
        Type type;
    };

    public:
        ArrayString(); // default constructor


        add(const String& p_value);
        bool containts(const String& p_value);
        int getSize() const;
        void getStrAt(int index) const;
        void getAllStrings() const;
        getType(const Vector<Typed>& p_type);
        getTyped(const Vector<Type>& p_value);

        // operator array 
        const String& operator[](int index);
        const String& operator[](int index) const;

        ArrayString& operator+=(const ArrayString& p_value);
        ArrayString& operator+(const ArrayString& p_value);
        ArrayString& operator&(const ArrayString& p_value);
        ArrayString& operator-(const ArrayString& p_value);
        ArrayString& operator*=(const String& p_value);
        ArrayString& operator*(const String& p_value);
        ArrayString& operator/=(const String& p_value);


        // additionale methods

        void Clear();
        void isEmpty();
        void Size(int p_size);
        void Sort();
        void roverts() const;
        void getSubArray(const ArrayString& p_lenght) const;

       private:
          std::vector <std::string> p_strings;
          static void bind_method();

};





#endif // ARRAY_STRING_H
