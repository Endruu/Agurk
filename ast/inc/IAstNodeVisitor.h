#pragma once

#include "AstFwd.h"

namespace ast
{

class IAstNodeVisitor
{
public:
    
    virtual void visit(ast::Background& obj) = 0;
    virtual void visit(ast::Comment& obj) = 0;
    virtual void visit(ast::DataTable& obj) = 0;
    virtual void visit(ast::DocString& obj) = 0;
    virtual void visit(ast::Example& obj) = 0;
    virtual void visit(ast::Feature& obj) = 0;
    virtual void visit(ast::Scenario& obj) = 0;
    virtual void visit(ast::ScenarioOutline& obj) = 0;
    virtual void visit(ast::Step& obj) = 0;
    virtual void visit(ast::TableCell& obj) = 0;
    virtual void visit(ast::TableRow& obj) = 0;
    virtual void visit(ast::Tag& obj) = 0;

protected:

    ~IAstNodeVisitor() {}
};

}
