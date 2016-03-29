#pragma once
	
#include "core/AstBase.h"
#include "core/KeywordNameDescription.h"
#include "Step.h"

#include <vector>

namespace ast
{

class ScenarioDefinition : public core::AstBase, public core::KeywordNameDescription
{
public:
    using StepContainer = std::vector<Step>;
    const StepContainer steps() const;

    virtual ~ScenarioDefinition() = 0;
};

}

