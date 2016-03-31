#pragma once
	
#include "ScenarioDefinition.h"
#include "core/TagContainerBase.h"

namespace ast
{

struct Scenario final : public ScenarioDefinition, public core::TagContainerBase
{

};

}

