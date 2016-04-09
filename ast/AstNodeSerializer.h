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

    void visit(Background& obj) override;
    void visit(Comment& obj) override;
    void visit(DataTable& obj) override;
    void visit(DocString& obj) override;
    void visit(Example& obj) override;
    void visit(Feature& obj) override;
    void visit(Scenario& obj) override;
    void visit(ScenarioOutline& obj) override;
    void visit(Step& obj) override;
    void visit(TableCell& obj) override;
    void visit(TableRow& obj) override;
    void visit(Tag& obj) override;

    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

}
