#pragma once

#include "Location.h"
#include "core/IAstNodeVisitor.h"

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

    virtual void accept(core::IAstNodeVisitor& visitor) = 0;
    virtual ~AstNode();
};

}
}

