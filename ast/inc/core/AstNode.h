#pragma once

#include <memory>
#include <string>

namespace ast
{

using string = std::string;
class Location;

namespace core
{

//#if __has_include(<experimental/propagate_const>)
//template <typename T>
//using ImplPtr = std::experimental::propagate_const<std::unique_ptr<T>>;
//#else
template <typename T>
using ImplPtr = std::unique_ptr<T>;
//#endif


class AstNode
{
public:
    const Location location() const;
    const string type() const;

    virtual ~AstNode();
};

}
}

