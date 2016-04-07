#pragma once

#include "IAstNodeVisitor.h"

#include <memory>

namespace ast
{

class AstNodeSerializer : public IAstNodeVisitor
{
public:
    AstNodeSerializer();
    ~AstNodeSerializer();

private:

    void visit(const Background& obj) override;
    void visit(const Comment& obj) override;
    void visit(const DataTable& obj) override;
    void visit(const DocString& obj) override;
    void visit(const Example& obj) override;
    void visit(const Feature& obj) override;
    void visit(const Scenario& obj) override;
    void visit(const ScenarioOutline& obj) override;
    void visit(const Step& obj) override;
    void visit(const TableCell& obj) override;
    void visit(const TableRow& obj) override;
    void visit(const Tag& obj) override;

    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

}
