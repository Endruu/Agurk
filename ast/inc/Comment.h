#pragma once
	
#include "core/AstNode.h"

namespace ast
{

struct Comment final : public core::AstNode
{
    string text;
};

}

