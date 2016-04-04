#pragma once
	
#include "StepArgument.h"

namespace ast
{

struct DocString final : public StepArgument
{
    string content;
    string contentType;

    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

