#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class Comment : public core::AstBase
{
public:
    const string text() const;
};

}

