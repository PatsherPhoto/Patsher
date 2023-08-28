#ifndef LIST_H
#define LIST_H


#include <map>
#include <list>

#include "core/string/string.h"

//
template <typename T>
class List {
    public:

        // constructor default
        List();
        //
        ~List();
        // emum api list 
        enum Node {
            LIST_STRING,
            LIST_ARRAY,
            LIST_MAP
        };
        enum Data {
            ACCESS,
            NODE,
            MAP
        };
        // void List
        void add(const T& item);
        void deleted(const T& item);
        void constaints(const T& item) const;
        void toList(const T& item) const;
        void toString(const String& p_str);
        void toMap();
        void StoreLine();
        void Store();
        void get_list();
        void get_property();
        void get_property_list(); 
        void get_lenght_list(); //
        void get_map_list(); //
        //
        int size() const;
        T& operator[](int index) const;
        bool IsEmpty();
    private:
        struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr);
        };
        Node* head;
        int count;
    
};





#endif // LIST_H