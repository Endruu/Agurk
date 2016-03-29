#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class Tag : public core::AstBase
{
public:
    const string name() const;
};

}

