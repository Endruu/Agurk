#pragma once

#include "ScenarioDefinition.h"

namespace ast
{

struct Background final : public ScenarioDefinition
{
    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

