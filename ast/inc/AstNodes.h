#pragma once

#include "AstFwd.h"
#include "IAstNodeVisitor.h"

#include <memory>
#include <string>
#include <vector>

namespace ast
{


namespace detail
{

struct KeywordNameDescription
{
    std::string keyword;
    std::string name;
    std::string description;

protected:
    ~KeywordNameDescription() {}
};


struct TagContainerBase
{
    using TagContainer = std::vector<Tag>;
    TagContainer tags;

protected:
    ~TagContainerBase() {}
};

}


struct Location final
{
    unsigned line;
    unsigned column;
};


struct AstNode
{
    std::string type;

    Location location;

    virtual void accept(IAstNodeVisitor& visitor) = 0;
    virtual ~AstNode() = 0 {}
};

struct Comment final : public AstNode
{
    std::string text;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct Feature final : public AstNode, public detail::TagContainerBase, public detail::KeywordNameDescription
{
    std::string language;

    using ScenarioDefinitionContainer = std::vector<std::unique_ptr<ScenarioDefinition>>;
    ScenarioDefinitionContainer scenarioDefinitions;

    using CommentContainer = std::vector<Comment>;
    CommentContainer comments;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct ScenarioDefinition : public AstNode, public detail::KeywordNameDescription
{
    using StepContainer = std::vector<Step>;
    StepContainer steps;

    virtual ~ScenarioDefinition() = 0;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct Background final : public ScenarioDefinition
{
    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct Scenario final : public ScenarioDefinition, public detail::TagContainerBase
{
    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct ScenarioOutline final : public ScenarioDefinition, public detail::TagContainerBase
{
    using ExampleContainer = std::vector<Example>;
    ExampleContainer examples;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct Step final : public AstNode
{
    std::unique_ptr<StepArgument> argument;

    std::string keyword;
    std::string text;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct StepArgument : public AstNode
{
    virtual ~StepArgument() = 0;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct DataTable final : public StepArgument
{
    using RowContainer = std::vector<TableRow>;
    RowContainer rows;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct DocString final : public StepArgument
{
    std::string content;
    std::string contentType;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct TableCell final : public AstNode
{
    std::string value;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct TableRow final : public AstNode
{
    using CellContainer = std::vector<TableCell>;
    CellContainer cells;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct Example final : public AstNode, public detail::TagContainerBase, public detail::KeywordNameDescription
{
    using RowContainer = std::vector<TableRow>;
    RowContainer rows;

    TableRow header;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


struct Tag final : public AstNode
{
    std::string name;

    void accept(IAstNodeVisitor& visitor) override { visitor.visit(*this); }
};


}
