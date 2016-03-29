#pragma once
	
#include "ScenarioDefinition.h"
#include "core/TagContainerBase.h"

namespace ast
{

class Scenario final : public ScenarioDefinition, public core::TagContainerBase
{
public:
    ~Scenario();
};

}

