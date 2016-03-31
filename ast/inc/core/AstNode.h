#pragma once

#include "Location.h"

#include <string>

namespace ast
{

using string = std::string;

namespace core
{

struct AstNode
{
    string type;

    Location location;

    virtual ~AstNode();
};

}
}

