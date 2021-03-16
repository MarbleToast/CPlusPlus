#include "BaseObject.h"

BaseObject::BaseObject(std::string name) : m_name(name) {}

std::vector<std::string> BaseObject::getVerbs() {
    return m_verbs;
}

void BaseObject::interact(std::string verb) {
    switch (verb) {
    default: 

    }
}
