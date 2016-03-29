#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class Comment final : public core::AstBase
{
public:
    const string text() const;
    ~Comment();
};

}

