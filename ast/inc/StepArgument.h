#pragma once
	
#include "core/AstNode.h"

namespace ast
{

class StepArgument : public core::AstNode
{
public:
    virtual ~StepArgument() = 0;
};

}

