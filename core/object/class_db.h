#ifndef CLASS_DB_H
#define CLASS_DB_H

#include "core/error/error_list.h"
#include "core/config/list.h"
#include "core/string/string.h"
#include "core/config/hash_map.h"
#include "core/object/ref.h"
#include "object.h"

#include <vector>
#include <map>
#include <string>
#include <functional>


/**
* @class ClassDB
* @author PatsherPhoto
* @version 2.0.0
*/
class BaseClass;
class ClassMap;
class Object;
class StringMap;
// new class 
class ClassDB : Object {
    public:
    GGClass(ClassDb, Object)
        //
        enum API {
            CORE,
            EDITOR,
            EXTENTIONS,
            ENGINE,
            CLASS,
            NONE
        };
        enum MethodInfo {
            M_METHOD,
            METHOD_NAME
        };
        //
        /**
         * @struct PropertySetGet 
        */
       struct PropertySetGet {
            int index;  
            String index;
            String Get;
            String Set;
            bool IsGet;
            bool IsSet;
       };
       struct PropertyInfo {
            Object& function;
            Object& GGClass;
       };
       template <class L>
       struct PropertyList {
            int size;
            String str_list;
            List<int> size_count;
            List<L> getItem;
            L& item;
       };
    // void ClassDB & Functions
    static ClassDB&  get_intstance();
    static void set_instance(const String& m_instance, const String& m_list_instance);
    static void get_list(const List<String>& m_list, const List<String> key_t, const String& key);
    static void get_parent(const String& m_parent);
    static bool can_instance(const String& m_instance);
    static void bind_methods(const std::string& p_methods, const MethodInfo& m_info);
    static void get_class(const String& m_class, const List<String>& m_class_list);
    static void get_enum_class(const String& m_enum_class, const List<String> m_enum_list);
    int get_class_count() const;
    int get_class_size(const std::string& class_name) const;
    std::vector<std::string> get_class_list() const;
    std::string get_class_name(std::string& class_name) const;
    BaseClass* get_child_class(const std::string& class_name) const;
    BaseClass* get_class(const  std::string& class_name) const; 
    template <typename T>
    static void rigister_methods(const std::string& p_method, T method);
    template <typename T>
    static void get_method(const std::string& p_method);
    auto it =  nullptr;
  



    static void get_enum_class_list(const String& enum_list, const List<String>& enum_class_list);
    static void get_enum(API _enum,const List<int> m_enum_count);
};
// 
class Class : public ClassDB {
    public:
        // GGCLass Interfaces
        struct ClassInfo {};
        enum ClassFunc {};
        enum ClassMethod {};
        // void Class
        static void ClassOperator(const String& m_class, const String& m_object); 
        static void Extend(const String& m_func, const String& m_object);
        static void Func(const List<String>& m_Func, const String& m_object);
    protected:
        
};

#endif // CLASS_DB_H
