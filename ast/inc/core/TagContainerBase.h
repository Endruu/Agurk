#pragma once

#include "Tag.h" //fwd decl

#include <vector>

namespace ast
{
namespace core
{

class TagContainerBase
{
public:
    using TagContainer = std::vector<Tag>;
    const TagContainer tags() const;

protected:
    ~TagContainerBase();
};

}
}

