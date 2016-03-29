#pragma once
	
#include "core/AstNode.h"
#include "core/KeywordNameDescription.h"
#include "Step.h"

#include <vector>

namespace ast
{

class ScenarioDefinition : public core::AstNode, public core::KeywordNameDescription
{
public:
    using StepContainer = std::vector<Step>;
    const StepContainer steps() const;

    virtual ~ScenarioDefinition() = 0;
};

}

