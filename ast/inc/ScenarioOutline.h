#pragma once
	
#include "ScenarioDefinition.h"
#include "Example.h"
#include "core/TagContainerBase.h"

#include <vector>

namespace ast
{

class ScenarioOutline final : public ScenarioDefinition, public core::TagContainerBase
{
public:
    using ExampleContainer = std::vector<Example>;
    const ExampleContainer examples() const;

    ~ScenarioOutline();
};

}

