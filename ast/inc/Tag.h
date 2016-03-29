#pragma once
	
#include "core/AstNode.h"

namespace ast
{

class Tag final : public core::AstNode
{
public:
    const string name() const;
    ~Tag();
};

}

