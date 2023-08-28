#ifndef THEME_H
#define THEME_H


#include "core/object/ref.h"
#include "core/config/list.h"
#include "core/object/object.h"

#include <string>
#include <map>
#include <vector>

class ThemeStyle;
class Font;
class ThemeResource;
class StylePanel;
template<typename T>
class ThemeInit;


class Theme : public Object {
    GGClass(Theme, Object)
    public:
    // NEW CONSTRUCTOR THEME
    Theme(const std::string& name, const std::vector<std::string>& colors);
    // ENUM API CLASS 
    enum Db {
        LIGHT,
        DARK,
        COSTUME
    };
    enum Style {};
    // STRUCT THEME NAMESPACE
    struct theme
    {
        bool isInit;
        bool isBold;
        int fontSize;

    };
    
    // NEW METHODS FOR THEME CLASS 
    void set(const std::string& name);
    void get() const;
    void get_colors(const std::vector<std::string>& colors) const;
    bool get_theme() const;
    void set_colors(const std::vector<std::string>& colors) const;
    void get_theme_list();
    bool get_theme_by_str() const;

    Db getType() const;
    void setType(Db type);
    void bind_methods(); 
    
private:
const std::string& p_name;
const std::vector<std::string>& p_colors;


};






#endif // THEME_H