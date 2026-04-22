#ifndef FACTORY_H
#define FACTORY_H

#include "SymString.h"
#include "OctString.h"

class Factory {
public:
    static SymString* CreateSymString(const std::string& id, const std::string& state);
    static OctString* CreateOctString(const std::string& id, const std::string& state);
    static void DeleteObject(SymString* obj);
};

#endif 