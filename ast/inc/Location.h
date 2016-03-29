#pragma once
	
#include "core/AstNode.h"

namespace ast
{

class Location final : public core::AstNode
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

