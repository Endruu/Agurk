#include "AstNodeSerializer.h"

#include "AstNodes.h"

#include "json.hpp"

using json = nlohmann::json;

struct ast::AstNodeSerializer::Impl
{
    static json serializeAst(ast::AstNode& obj)
    {
        AstNodeSerializer serializer;
        obj.accept(serializer);
        return serializer.pImpl->result;
    }

    static void setResult(ast::AstNodeSerializer& serializer, const json& result)
    {
        serializer.pImpl->result = result;
    }

    template<typename T>
    static std::vector<json> serializeContainer(T& container)
    {
        std::vector<json> serialized;

        serialized.reserve(container.size());

        for (auto& elem : container)
        {
            serialized.push_back(serializeAst(elem));
        }

        return serialized;
    }

    static json Impl::serializeAstNodeBase(ast::AstNode& obj, const std::string& type)
    {
        json j;

        j["location"]["column"] = obj.location.column;
        j["location"]["line"] = obj.location.line;
        j["type"] = type;

        return j;
    }

    static void Impl::serializeKwd(ast::detail::KeywordNameDescription& obj, json& j)
    {
        j["keyword"] = obj.keyword;
        j["name"] = obj.name;
        j["description"] = obj.description;
    }

    static void serializeTagContainer(ast::detail::TagContainerBase& obj, json& j)
    {
        j["tags"] = serializeContainer(obj.tags);
    }

    static void serializeScenarioDefinition(ast::ScenarioDefinition& obj, json& j)
    {
        serializeKwd(obj, j);
        j["steps"] = serializeContainer(obj.steps);
    }


private:
    json result;
};

ast::AstNodeSerializer::AstNodeSerializer() : pImpl(new ast::AstNodeSerializer::Impl) {}
ast::AstNodeSerializer::~AstNodeSerializer() {}

const std::string ast::AstNodeSerializer::serialize(AstNode& node, int indent)
{
    return Impl::serializeAst(node).dump(indent);
}


void ast::AstNodeSerializer::visit(ast::Background& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Background");
    Impl::serializeScenarioDefinition(obj, j);
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::Comment& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Comment");
    j["text"] = obj.text;
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::DataTable& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "DataTable");
    j["rows"] = Impl::serializeContainer(obj.rows);
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::DocString& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "DocString");
    j["content"] = obj.content;
    j["contentType"] = obj.contentType;
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::Example& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Example");
    Impl::serializeKwd(obj, j);
    Impl::serializeTagContainer(obj, j);
    j["header"] = Impl::serializeAst(obj.header);
    j["rows"] = Impl::serializeContainer(obj.rows);
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::Feature& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Feature");
    Impl::serializeKwd(obj, j);
    Impl::serializeTagContainer(obj, j);

    j["language"] = obj.language;

    std::vector<json> serialized;
    serialized.reserve(obj.scenarioDefinitions.size());
    for (auto& scenarioDefinition : obj.scenarioDefinitions)
    {
        //TODO: check ptr, but in theory it should never be empty
        serialized.push_back(Impl::serializeAst(*scenarioDefinition));
    }

    j["scenarioDefinitions"] = serialized;   //TODO: name is probably not scenarioDefinitions

    j["comments"] = Impl::serializeContainer(obj.comments);

    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::Scenario& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Scenario");
    Impl::serializeTagContainer(obj, j);
    Impl::serializeScenarioDefinition(obj, j);
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::ScenarioOutline& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "ScenarioOutline");
    Impl::serializeTagContainer(obj, j);
    Impl::serializeScenarioDefinition(obj, j);
    j["examples"] = Impl::serializeContainer(obj.examples);
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::Step& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Step");
    j["keyword"] = obj.keyword;
    j["text"] = obj.text;

    if (obj.argument)
    {
        j["argument"] = Impl::serializeAst(*obj.argument);
    }
    else
    {
        j["argument"] = nullptr;
    }

    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::TableCell& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "TableCell");
    j["value"] = obj.value;
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::TableRow& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "TableRow");
    j["cells"] = Impl::serializeContainer(obj.cells);
    Impl::setResult(*this, j);
}


void ast::AstNodeSerializer::visit(ast::Tag& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Tag");
    j["name"] = obj.name;
    Impl::setResult(*this, j);
}
