#pragma once
	
#include "core/AstNode.h"

namespace ast
{

struct TableCell final : public core::AstNode
{
    string value;

    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

