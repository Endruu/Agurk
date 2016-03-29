#pragma once
	
#include "StepArgument.h"

namespace ast
{

class DocString final : public StepArgument
{
public:
    const string content() const;
    const string contentType() const;
    ~DocString();
};

}

