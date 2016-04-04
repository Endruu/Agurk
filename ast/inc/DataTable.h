#pragma once
	
#include "StepArgument.h"
#include "TableRow.h"

#include <vector>

namespace ast
{

struct DataTable final : public StepArgument
{
    using RowContainer = std::vector<TableRow>;
    RowContainer rows;

    void accept(core::IAstNodeVisitor& visitor) override { visitor.visit(*this); };
};

}

