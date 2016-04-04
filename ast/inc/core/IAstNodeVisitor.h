#pragma once

namespace ast
{

struct Background;
struct Comment;
struct DataTable;
struct DocString;
struct Example;
struct Feature;
struct Location;
struct Scenario;
struct ScenarioDefinition;
struct ScenarioOutline;
struct Step;
struct StepArgument;
struct TableCell;
struct TableRow;
struct Tag;

namespace core
{

class IAstNodeVisitor
{
public:
    
    virtual void visit(const Background& obj) = 0;
    virtual void visit(const Comment& obj) = 0;
    virtual void visit(const DataTable& obj) = 0;
    virtual void visit(const DocString& obj) = 0;
    virtual void visit(const Example& obj) = 0;
    virtual void visit(const Feature& obj) = 0;
    virtual void visit(const Location& obj) = 0;
    virtual void visit(const Scenario& obj) = 0;
    virtual void visit(const ScenarioDefinition& obj) = 0;
    virtual void visit(const ScenarioOutline& obj) = 0;
    virtual void visit(const Step& obj) = 0;
    virtual void visit(const StepArgument& obj) = 0;
    virtual void visit(const TableCell& obj) = 0;
    virtual void visit(const TableRow& obj) = 0;
    virtual void visit(const Tag& obj) = 0;

protected:

    ~IAstNodeVisitor() {};
};

}
}
