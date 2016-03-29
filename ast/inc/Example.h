#pragma once
	
#include "core/AstBase.h"
#include "core/TagContainerBase.h"
#include "core/KeywordNameDescription.h"
#include "TableRow.h"

#include <vector>

namespace ast
{

class Example final : public core::AstBase, public core::TagContainerBase, public core::KeywordNameDescription
{
public:
    const TableRow header() const;
    using RowContainer = std::vector<TableRow>;
    const RowContainer rows() const;
    ~Example();
};

}

