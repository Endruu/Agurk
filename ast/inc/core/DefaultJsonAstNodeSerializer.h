#pragma once

#include "core/IAstNodeSerializer.h"

namespace ast
{
namespace core
{

class DefaultJsonAstNodeSerializer : public core::IAstNodeSerializer
{
public:

    const string serialize(const Background& obj) override;
    const string serialize(const Comment& obj) override;
    const string serialize(const DataTable& obj) override;
    const string serialize(const DocString& obj) override;
    const string serialize(const Example& obj) override;
    const string serialize(const Feature& obj) override;
    const string serialize(const Location& obj) override;
    const string serialize(const Scenario& obj) override;
    const string serialize(const ScenarioOutline& obj) override;
    const string serialize(const Step& obj) override;
    const string serialize(const TableCell& obj) override;
    const string serialize(const TableRow& obj) override;
    const string serialize(const Tag& obj) override;

    const string serialize(const AstNode& obj) override;

    virtual ~DefaultJsonAstNodeSerializer();
};

}
}