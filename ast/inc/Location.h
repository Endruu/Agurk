#pragma once
	
#include "core/AstBase.h"

namespace ast
{

class Location : public core::AstBase
{
public:
    inline int line() const { return _line; }
    inline int column() const { return _column; }
    Location(int line, int column) : _line(line), _column(column) {}

private:
    const int _line;
    const int _column;
};

}

