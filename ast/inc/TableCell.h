#pragma once
	
#include "core/AstNode.h"

namespace ast
{

class TableCell final : public core::AstNode
{
public:
    const string value() const;

    ~TableCell();
};

}

