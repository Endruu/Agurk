#pragma once
	
#include "core/AstBase.h"
#include "core/TagContainer.h"
#include "core/KeywordNameDescription.h"

namespace ast
{

class Feature : public core::AstBase, public core::TagContainer, public core::KeywordNameDescription
{
public:
    const string language() const;

};

}

