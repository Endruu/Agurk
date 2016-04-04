#pragma once

#include "core/IAstNodeVisitor.h"

namespace ast
{
namespace core
{

class DefaultJsonAstNodeSerializer : public core::IAstNodeVisitor
{
public:

    void visit(const Background& obj) override;
    void visit(const Comment& obj) override;
    void visit(const DataTable& obj) override;
    void visit(const DocString& obj) override;
    void visit(const Example& obj) override;
    void visit(const Feature& obj) override;
    void visit(const Location& obj) override;
    void visit(const Scenario& obj) override;
    void visit(const ScenarioDefinition& obj) override;
    void visit(const ScenarioOutline& obj) override;
    void visit(const Step& obj) override;
    void visit(const StepArgument& obj) override;
    void visit(const TableCell& obj) override;
    void visit(const TableRow& obj) override;
    void visit(const Tag& obj) override;

};

}
}