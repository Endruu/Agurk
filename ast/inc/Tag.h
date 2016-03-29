#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class Tag final : public core::AstBase
{
public:
    const string name() const;
    ~Tag();
};

}

