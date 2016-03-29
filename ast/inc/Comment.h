#pragma once
	
#include "core/AstNode.h"

namespace ast
{

class Comment final : public core::AstNode
{
public:
    const string text() const;
    ~Comment();
};

}

