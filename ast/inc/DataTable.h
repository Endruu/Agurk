#pragma once
	
#include "StepArgument.h"
#include "TableRow.h"

#include <vector>

namespace ast
{

class DataTable final : public StepArgument
{
public:
    using RowContainer = std::vector<TableRow>;
    const RowContainer rows() const;
    ~DataTable();
};

}

