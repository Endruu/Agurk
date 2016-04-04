#pragma once
	
#include "core/AstNode.h"

namespace ast
{

struct Tag final : public core::AstNode
{
    string name;

    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

