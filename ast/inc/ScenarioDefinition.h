#pragma once
	
#include "core/AstNode.h"
#include "core/KeywordNameDescription.h"
#include "Step.h"

#include <vector>

namespace ast
{

struct ScenarioDefinition : public core::AstNode, public core::KeywordNameDescription
{
    using StepContainer = std::vector<Step>;
    StepContainer steps;

    virtual ~ScenarioDefinition() = 0;
};

}

