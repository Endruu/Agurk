#pragma once
	
#include "core/AstNode.h"
#include "core/TagContainerBase.h"
#include "core/KeywordNameDescription.h"

#include "ScenarioDefinition.h"
#include "Comment.h"

#include <vector>
#include <memory>

namespace ast
{

struct Feature final : public core::AstNode, public core::TagContainerBase, public core::KeywordNameDescription
{
    string language;
    
    using ScenarioDefinitionContainer = std::vector<std::unique_ptr<ScenarioDefinition>>;
    ScenarioDefinitionContainer scenarioDefinitions;

    using CommentContainer = std::vector<Comment>;
    CommentContainer comments;

    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

