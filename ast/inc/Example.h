#pragma once
	
#include "core/AstNode.h"
#include "core/TagContainerBase.h"
#include "core/KeywordNameDescription.h"
#include "TableRow.h"

#include <vector>

namespace ast
{

struct Example final : public core::AstNode, public core::TagContainerBase, public core::KeywordNameDescription
{
    using RowContainer = std::vector<TableRow>;
    RowContainer rows;

    TableRow header;

    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

