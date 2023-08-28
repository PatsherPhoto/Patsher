#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H


#include "core/config/list.h"
#include <array>
#include <memory>


class ResourceManager;
class ResourceLoader {
    public:
        void load();
        bool isLoad();
        void getPath();
        void setPath();
        void getResource();

        /**
         * @enum ResourceType
        */
       enum ResourceType {
            MODE,
            LOADER,
            ACCESS,
            SYSTEMS
       };
       enum ResourceGeter {
            
       };
    protected:
        //
        static void bind_methods();
        static void bind_class();
    private:
        //

};




#endif // RESOURCE_LOADER_H