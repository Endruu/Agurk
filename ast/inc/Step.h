#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class Step : public core::AstBase
{
public:
    const string keyword() const;
    const string text() const;
};

}

