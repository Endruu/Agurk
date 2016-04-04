#pragma once
	
#include "ScenarioDefinition.h"
#include "core/TagContainerBase.h"

namespace ast
{

struct Scenario final : public ScenarioDefinition, public core::TagContainerBase
{
    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

