#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class TableCell final : public core::AstBase
{
public:
    const string value() const;

    ~TableCell();
};

}

