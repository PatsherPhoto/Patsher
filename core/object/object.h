#ifndef OBJECT_H
#define OBJECT_H

#include "core/string/string.h"
#include "core/config/list.h"
#include "core/config/hash_map.h"
#include "ref.h"
#include "class_db.h"



class Variant;
class MethodInfo;
class GDExtensionClassGetPropertyList;
class ScriptInstance;
class PropertyInfo;
// 
class Object {
    public:
    enum ObjectInfo {
        PROPERTY_HINT_NONE, ///< no hint provided.
        PROPERTY_HINT_RANGE, ///< hint_text = "min,max[,step][,or_greater][,or_less][,hide_slider][,radians][,degrees][,exp][,suffix:<keywor>
        PROPERTY_HINT_ENUM, ///< hint_text= "val1,val2,val3,etc"
        PROPERTY_HINT_ENUM_SUGGESTION, ///< hint_text= "val1,val2,val3,etc"
        PROPERTY_HINT_EXP_EASING, /// exponential easing function (Math::ease) use "attenuation" hint string to revert (flip h), "positive_o>
        PROPERTY_HINT_LINK,
        PROPERTY_HINT_FLAGS, ///< hint_text= "flag1,flag2,etc" (as bit flags)
        PROPERTY_HINT_LAYERS_2D_RENDER,
        PROPERTY_HINT_LAYERS_2D_PHYSICS,
        PROPERTY_HINT_LAYERS_2D_NAVIGATION,
        PROPERTY_HINT_LAYERS_3D_RENDER,
        PROPERTY_HINT_LAYERS_3D_PHYSICS,
        PROPERTY_HINT_LAYERS_3D_NAVIGATION,
        PROPERTY_HINT_FILE, ///< a file path must be passed, hint_text (optionally) is a filter "*.png,*.wav,*.doc,"
        PROPERTY_HINT_DIR, ///< a directory path must be passed
        PROPERTY_HINT_GLOBAL_FILE, ///< a file path must be passed, hint_text (optionally) is a filter "*.png,*.wav,*.doc,"
        PROPERTY_HINT_GLOBAL_DIR, ///< a directory path must be passed
        PROPERTY_HINT_RESOURCE_TYPE, ///< a resource object type
        PROPERTY_HINT_MULTILINE_TEXT, ///< used for string properties that can contain multiple lines
        PROPERTY_HINT_EXPRESSION, ///< used for string properties that can contain multiple lines
        PROPERTY_HINT_PLACEHOLDER_TEXT, ///< used to set a placeholder text for string properties
        PROPERTY_HINT_COLOR_NO_ALPHA, ///< used for ignoring alpha component when editing a color
        PROPERTY_HINT_OBJECT_ID,
        PROPERTY_HINT_TYPE_STRING, ///< a type string, the hint is the base type to choose
        PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE, ///< so something else can provide this (used in scripts)
        PROPERTY_HINT_OBJECT_TOO_BIG, ///< object is too big to send
        PROPERTY_HINT_NODE_PATH_VALID_TYPES,
        PROPERTY_HINT_SAVE_FILE, ///< a file path must be passed, hint_text (optionally) is a filter "*.png,*.wav,*.doc,". This opens a save>
        PROPERTY_HINT_GLOBAL_SAVE_FILE, ///< a file path must be passed, hint_text (optionally) is a filter "*.png,*.wav,*.doc,". This opens>
        PROPERTY_HINT_INT_IS_OBJECTID,
        PROPERTY_HINT_INT_IS_POINTER,
        PROPERTY_HINT_ARRAY_TYPE,
        PROPERTY_HINT_LOCALE_ID,
        PROPERTY_HINT_LOCALIZABLE_STRING,
        PROPERTY_HINT_NODE_TYPE, ///< a node object type
        PROPERTY_HINT_HIDE_QUATERNION_EDIT, /// Only Node3D::transform should hide the quaternion editor.
        PROPERTY_HINT_PASSWORD,
        PROPERTY_HINT_LAYERS_AVOIDANCE,
        PROPERTY_HINT_MAX
    };
    enum Info {
        PROPERTY_USAGE_NONE = 0,
        PROPERTY_USAGE_STORAGE = 1 << 1,
        PROPERTY_USAGE_EDITOR = 1 << 2,
        PROPERTY_USAGE_INTERNAL = 1 << 3,
        PROPERTY_USAGE_CHECKABLE = 1 << 4, // Used for editing global variables.
        PROPERTY_USAGE_CHECKED = 1 << 5, // Used for editing global variables.
        PROPERTY_USAGE_GROUP = 1 << 6, // Used for grouping props in the editor.
        PROPERTY_USAGE_CATEGORY = 1 << 7,
        PROPERTY_USAGE_SUBGROUP = 1 << 8,
        PROPERTY_USAGE_CLASS_IS_BITFIELD = 1 << 9,
        PROPERTY_USAGE_NO_INSTANCE_STATE = 1 << 10,
        PROPERTY_USAGE_RESTART_IF_CHANGED = 1 << 11,
        PROPERTY_USAGE_SCRIPT_VARIABLE = 1 << 12,
        PROPERTY_USAGE_STORE_IF_NULL = 1 << 13,
        PROPERTY_USAGE_UPDATE_ALL_IF_MODIFIED = 1 << 14,
        PROPERTY_USAGE_SCRIPT_DEFAULT_VALUE = 1 << 15,
        PROPERTY_USAGE_CLASS_IS_ENUM = 1 << 16,
        PROPERTY_USAGE_NIL_IS_VARIANT = 1 << 17,
        PROPERTY_USAGE_ARRAY = 1 << 18, // Used in the inspector to group properties as elements of an array.
        PROPERTY_USAGE_ALWAYS_DUPLICATE = 1 << 19, // When duplicating a resource, always duplicate, even with subresource duplication disab>
        PROPERTY_USAGE_NEVER_DUPLICATE = 1 << 20, // When duplicating a resource, never duplicate, even with subresource duplication enabled.
        PROPERTY_USAGE_HIGH_END_GFX = 1 << 21,
        PROPERTY_USAGE_NODE_PATH_FROM_SCENE_ROOT = 1 << 22,
        PROPERTY_USAGE_RESOURCE_NOT_PERSISTENT = 1 << 23,
        PROPERTY_USAGE_KEYING_INCREMENTS = 1 << 24, // Used in inspector to increment property when keyed in animation player.
        PROPERTY_USAGE_DEFERRED_SET_RESOURCE = 1 << 25, // when loading, the resource for this property can be set at the end of loading.
        PROPERTY_USAGE_EDITOR_INSTANTIATE_OBJECT = 1 << 26, // For Object properties, instantiate them when creating in editor.
        PROPERTY_USAGE_EDITOR_BASIC_SETTING = 1 << 27, //for project or editor settings, show when basic settings are selected.
        PROPERTY_USAGE_READ_ONLY = 1 << 28, // Mark a property as read-only in the inspector.
        PROPERTY_USAGE_SECRET = 1 << 29, // Export preset credentials that should be stored separately from the rest of the export config.

        PROPERTY_USAGE_DEFAULT = PROPERTY_USAGE_STORAGE | PROPERTY_USAGE_EDITOR,
        PROPERTY_USAGE_NO_EDITOR = PROPERTY_USAGE_STORAGE

    };
    enum BindObject {
        METHOD_FLAG_NORMAL = 1,
        METHOD_FLAG_EDITOR = 2,
        METHOD_FLAG_CONST = 4,
        METHOD_FLAG_VIRTUAL = 8,
        METHOD_FLAG_VARARG = 16,
        METHOD_FLAG_STATIC = 32,
        METHOD_FLAG_OBJECT_CORE = 64,
        METHOD_FLAGS_DEFAULT = METHOD_FLAG_NORMAL
    };
    struct MethodInfo {
        String name;
        int id = 0;
    };


    inline bool operator==(const MethodInfo &p_method);
    inline bool operator<(const MethodInfo &p_method);

class MethodBind;
class GGExtension;


struct ObjectGGExtension {
        GGExtension *library = nullptr;
        ObjectGGExtension *parent = nullptr;
        List<ObjectGGExtension *> children;
        StringName parent_class_name;
        StringName class_name;
        bool editor_class = false;                                                                           bool is_virtual = false;
        bool is_abstract = false;
    };

    enum ConnectFlags {
                CONNECT_DEFERRED = 1,
                CONNECT_PERSIST = 2, // hint for scene to save this connection
                CONNECT_ONE_SHOT = 4,
                CONNECT_REFERENCE_COUNTED = 8,
                CONNECT_INHERITED = 16, // Used in editor builds.
    };

    virtual void _initialize_classv() {}
        virtual bool _setv(const StringName &p_name, const Variant &p_property) { return false; };
        virtual bool _getv(const StringName &p_name, Variant &r_property) const { return false; };
        virtual void _get_property_listv(List<PropertyInfo> *p_list, bool p_reversed) const {};
        virtual void _validate_propertyv(PropertyInfo &p_property) const {};
        virtual bool _property_can_revertv(const StringName &p_name) const { return false; };
        virtual bool _property_get_revertv(const StringName &p_name, Variant &r_property);
        virtual void _notificationv(int p_notification, bool p_reversed) {}


        static void _bind_methods();
        static void _bind_compatibility_methods() {}
        bool _set(const StringName &p_name, const Variant &p_property) { return false; };
        bool _get(const StringName &p_name, Variant &r_property) const { return false; };
        void _get_property_list(List<PropertyInfo> *p_list) const {};
        void _validate_property(PropertyInfo &p_property) const {};
        bool _property_can_revert(const StringName &p_name) const { return false; };
        bool _property_get_revert(const StringName &p_name, Variant &r_property) const { return false; };
        void _notification(int p_notification) {}





    private:
    #define GGClass(p_class, p_init)
    void operator=(const String& p_evrt) {}
    friend class::ClassDB;
    
};

class ObjectDB {
// This needs to add up to 63, 1 bit is for reference.
#define OBJECTDB_VALIDATOR_BITS 39
#define OBJECTDB_VALIDATOR_MASK ((uint64_t(1) << OBJECTDB_VALIDATOR_BITS) - 1)
#define OBJECTDB_SLOT_MAX_COUNT_BITS 24
#define OBJECTDB_SLOT_MAX_COUNT_MASK ((uint64_t(1) << OBJECTDB_SLOT_MAX_COUNT_BITS) - 1)
#define OBJECTDB_REFERENCE_BIT (uint64_t(1) << (OBJECTDB_SLOT_MAX_COUNT_BITS + OBJECTDB_VALIDATOR_BITS))

        struct ObjectSlot { // 128 bits per slot.
                uint64_t validator : OBJECTDB_VALIDATOR_BITS;
                uint64_t next_free : OBJECTDB_SLOT_MAX_COUNT_BITS;
                uint64_t is_ref_counted : 1;
                Object *object = nullptr;
        };
};

#endif // OBJECT_H