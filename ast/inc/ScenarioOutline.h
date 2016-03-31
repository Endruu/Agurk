#pragma once
	
#include "ScenarioDefinition.h"
#include "Example.h"
#include "core/TagContainerBase.h"

#include <vector>

namespace ast
{

struct ScenarioOutline final : public ScenarioDefinition, public core::TagContainerBase
{
    using ExampleContainer = std::vector<Example>;
    ExampleContainer examples;
};

}

