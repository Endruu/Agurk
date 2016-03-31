#pragma once

#include "core/AstNode.h"
#include "StepArgument.h"

#include <memory>

namespace ast
{

struct Step final : public core::AstNode
{
    std::unique_ptr<StepArgument> argument;

    string keyword;
    string text;
    
};

}

