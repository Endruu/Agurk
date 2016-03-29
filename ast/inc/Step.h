#pragma once
	
#include "core/AstBase.h"
#include "StepArgument.h"

namespace ast
{

class Step final : public core::AstBase
{
public:
    const string keyword() const;
    const string text() const;

    const StepArgument* argument() const;

    ~Step();
};

}

