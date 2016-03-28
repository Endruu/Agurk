#pragma once
	
#include "ScenarioDefinition.h"
#include "core/TagContainer.h"

namespace ast
{

class Scenario : public ScenarioDefinition, public core::TagContainer
{

};

}

