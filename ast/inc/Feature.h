#pragma once
	
#include "core/AstNode.h"
#include "core/TagContainerBase.h"
#include "core/KeywordNameDescription.h"

#include "ScenarioDefinition.h"
#include "Comment.h"

#include <vector>

namespace ast
{

class Feature final : public core::AstNode, public core::TagContainerBase, public core::KeywordNameDescription
{
public:
    const string language() const;
    using ScenarioDefinitionContainer = std::vector<const ScenarioDefinition&>;
    using CommentContainer = std::vector<Comment>;

    const CommentContainer comments() const;
    const ScenarioDefinitionContainer scenarioDefinitions() const;

    ~Feature();

};

}

