#pragma once

#include "core/AstBase.h"

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
};

}
}