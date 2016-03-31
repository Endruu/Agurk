#pragma once
	
#include "StepArgument.h"

namespace ast
{

struct DocString final : public StepArgument
{
    string content;
    string contentType;
};

}

