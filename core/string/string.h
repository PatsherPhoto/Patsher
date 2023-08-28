#ifndef STRING_NAME_H
#define STRING_NAME_H


#include <string>
#include <unordered_map>
#include <cstring>

#include "core/config/list.h"
#include "core/object/class_db.h"

template <typename T>
class TypedArray;
class String;
class Char32String;
class Char64String;
class StringName {
    public:
        // default 
        StringName();
        // enum
        /**
         * @enum HashFunc
         * */ 
        enum class HashFunc {
            STR,
            NAME,
            NODESTRING
        };
    protected:
        // class db to save class St
        static void rigister_class();
        static void bind_method();
    private:
        //
};


class String {
    //
    public:
        enum StrType {

        };
        enum Str {
            STR,
            NAME,
            VALUE
        };
        // constructor ```String Class```
        String();
        explicit String(const char* str);
        String(const String& str);
        // String Data Class 
        const char* getData() const;
        int getLenght() const;
        StrType getType() const;
        Str getStr() const;
        Str setStr() const;

        // void String
        void append(const char* str);
        void append(const String& p_str);
        bool isEmpty();
        void appnedValue(const List<String>& p_list);
        void toString(const List<String>& p_list);
        void name(const String& p_name);
        String& operator=(const String& p_str);
        void get_parent_str(const String& p_parent, const List<String>& p_str);
        void get_parent_list(const String& name, const List<String>& p_list); // get all parent 
        void get(const String& key);
        void set(const String& key);
        void get_parent_value();
        void get_value(); 
        void get_value_data();
        void get_data();
        void join(const String& join);
        void pathJoin(const String& path);
        // 
    private:
        char* data; // pointer of the String class 
        int lenght; // lenght of the String
        void callocate(const char* source);
        void dallocate(); // helper function dallocate
    protected:
        static void bind_methods();
        static void bind_class();
};

class Char32String : public String {

};

class Char64String : public String {

};

#endif // STRING_NAME_H