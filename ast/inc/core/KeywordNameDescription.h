#pragma once

#include "core/AstNode.h"

namespace ast
{
namespace core
{

class KeywordNameDescription
{
public:
    const string keyword() const;
    const string name() const;
    const string description() const;

protected:
    ~KeywordNameDescription();
};

}
}