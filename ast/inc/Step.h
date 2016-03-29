#pragma once
	
#include "core/AstNode.h"
#include "StepArgument.h"

namespace ast
{

class Step final : public core::AstNode
{
public:
    const string keyword() const;
    const string text() const;

    const StepArgument* argument() const;

    ~Step();
};

}

