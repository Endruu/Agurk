#pragma once

#include "AstFwd.h"

namespace ast
{

namespace core
{

class IAstNodeVisitor
{
public:
    
    virtual void visit(const ast::Background& obj) = 0;
    virtual void visit(const ast::Comment& obj) = 0;
    virtual void visit(const ast::DataTable& obj) = 0;
    virtual void visit(const ast::DocString& obj) = 0;
    virtual void visit(const ast::Example& obj) = 0;
    virtual void visit(const ast::Feature& obj) = 0;
    virtual void visit(const ast::Location& obj) = 0;
    virtual void visit(const ast::Scenario& obj) = 0;
    virtual void visit(const ast::ScenarioDefinition& obj) = 0;
    virtual void visit(const ast::ScenarioOutline& obj) = 0;
    virtual void visit(const ast::Step& obj) = 0;
    virtual void visit(const ast::StepArgument& obj) = 0;
    virtual void visit(const ast::TableCell& obj) = 0;
    virtual void visit(const ast::TableRow& obj) = 0;
    virtual void visit(const ast::Tag& obj) = 0;

protected:

    ~IAstNodeVisitor() {};
};

}
}