#pragma once
	
#include "core/AstNode.h"
#include "TableCell.h"

#include <vector>

namespace ast
{

struct TableRow final : public core::AstNode
{
    using CellContainer = std::vector<TableCell>;
    CellContainer cells;
};

}

