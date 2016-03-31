#pragma once
	
#include "core/AstNode.h"

namespace ast
{

struct TableCell final : public core::AstNode
{
    string value;
};

}

