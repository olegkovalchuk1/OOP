#include "Factory.h"

SymString* Factory::CreateSymString(const std::string& id, const std::string& state) {
    return new SymString(id, state);
}

OctString* Factory::CreateOctString(const std::string& id, const std::string& state) {
    return new OctString(id, state);
}

void Factory::DeleteObject(SymString* obj) {
    if (obj) {
        delete obj;
    }
}