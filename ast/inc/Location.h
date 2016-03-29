#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class Location final : public core::AstBase
{
public:
    inline unsigned line() const { return _line; }
    inline unsigned column() const { return _column; }
    Location(unsigned line, unsigned column) : _line(line), _column(column) {}

private:
    const unsigned _line;
    const unsigned _column;
};

}

