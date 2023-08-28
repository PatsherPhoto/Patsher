#include "theme.h"
#include "core/object/class_db.h"
#include <map>
#include <string>
#include <vector>

Theme::Theme(const std::string& name, const std::vector<std::string>& colors, Db type) : name(name), color(color), type(type) {}

void Theme::set(const std::string& name) {
    this->name = name;
}

bool Theme::get() const {
    return;
}
bool Theme::get_colors(const std::vector<std::string>& colors) const{
    return colors = colors;
}
void Theme::set_colors(const std::vector<std::string>& colors) const {
    this-> colors = colors;
}
void Theme::setType(Db type) {
    this-> type = type;
}
void Theme::bind_methods() {
    ClassDB::bind_methods("get_theme", Theme::get_theme);
    ClassDB::bind_methods("set_colors", Theme::get_colors);
    ClassDB::bind_methods("set_type", Theme:Db type);
    ClassDB::bind_methods("get", Theme::get);
    ClassDB::bind_methods("set", Theme::set);
}