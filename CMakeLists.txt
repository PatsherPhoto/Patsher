# cmake 
cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD)
set(CMAKE_CXX_EXTENSIONS)
set(CMAKE_CXX_STANDARD_REQUIRED)
# On Project List Source
set( 
    core/config/engine.cpp 
    core/config/engine.h 
    core/config/list.cpp
    core/config/list.h 
    core/config/hash_map.cpp 
    core/config/hash_map.h
    core/config/project.cpp 
    core/config/project.h 
    core/config/project_settings.cpp 
    core/config/project_settings.h
    core/debugger/debug.cpp 
    core/debugger/debug.h
    core/animation/plugins/animation_editor.cpp 
    core/animation/plugins/animation_editor.h 
    core/animation/plugins/animation_gui_editor.cpp
    core/animation/plugins/animation_gui_editor.h 
    core/animation/plugins/animation_map.cpp 
    core/animation/plugins/animation_map.h 
    core/animation/plugins/animation.cpp 
    core/animation/plugins/animation.h 
    core/drives/vulkan/vulkan.cpp 
    core/drives/vulkan/vulkan.h 
    core/error/error_list.cpp 
    core/error/error_list.h 
    core/math/array.cpp 
    core/math/array.h 
    core/math/array_string.cpp
    core/math/array_string.h
    core/math/rect2.cpp 
    core/math/rect2.h
    core/math/vector.cpp 
    core/math/vector.h
    core/math/vector2.cpp
    core/math/vector2.h
    core/math/vector3.cpp
    core/math/vector3.h
    core/math/vector4.cpp
    core/math/vector4.h
    core/math/math_func.cpp
    core/math/math_func.h
    core/input/keyboard.cpp
    core/input/keyboard.h 
    core/input/event.cpp
    core/input/event.h
    core/input/event_lisent.cpp
    core/input/event_lisent.h 


)
# new project 
project(patsher LANGUAGE CXX_STANDARD)

