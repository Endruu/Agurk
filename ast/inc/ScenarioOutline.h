#pragma once
	
#include "ScenarioDefinition.h"
#include "Examples.h"
#include "core/TagContainerBase.h"

#include <vector>

namespace ast
{

class ScenarioOutline final : public ScenarioDefinition, public core::TagContainerBase
{
public:
    using ExampleContainer = std::vector<Examples>;
    const ExampleContainer examples() const;

    ~ScenarioOutline();
};

}

