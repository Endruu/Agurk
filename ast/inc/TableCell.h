#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class TableCell : public core::AstBase
{
public:
    const string value() const;
};

}

