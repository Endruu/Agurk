#pragma once
	
#include "core/AstNode.h"

namespace ast
{

struct StepArgument : public core::AstNode
{
    virtual ~StepArgument() = 0;

    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

