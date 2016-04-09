#include "AstNodeSerializer.h"

#include "AstNodes.h"

#include "json.hpp"

using json = nlohmann::json;

struct ast::AstNodeSerializer::Impl
{
    json result;

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
        std::vector<json> serialized;

        serialized.reserve(obj.tags.size());

        for (auto& tag : obj.tags)
        {
            serialized.push_back(serializeAst(tag));
        }

        j["tags"] = serialized;
    }

    static json serializeAst(ast::AstNode& obj)
    {
        AstNodeSerializer serializer;
        obj.accept(serializer);
        return serializer.pImpl->result;
    }
};

ast::AstNodeSerializer::AstNodeSerializer() : pImpl(new ast::AstNodeSerializer::Impl) {}
ast::AstNodeSerializer::~AstNodeSerializer() {}


void ast::AstNodeSerializer::visit(ast::Background& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Background");
    Impl::serializeKwd(obj, j);
}


void ast::AstNodeSerializer::visit(ast::Comment& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Comment");
}


void ast::AstNodeSerializer::visit(ast::DataTable& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "DataTable");
}


void ast::AstNodeSerializer::visit(ast::DocString& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "DocString");
}


void ast::AstNodeSerializer::visit(ast::Example& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Example");
    Impl::serializeKwd(obj, j);
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
    
    serialized.clear();
    serialized.shrink_to_fit();
    serialized.reserve(obj.scenarioDefinitions.size());
    for (auto& comment : obj.comments)
    {
        //TODO: check ptr, but in theory it should never be empty
        serialized.push_back(Impl::serializeAst(comment));
    }
    
    j["comments"] = serialized;

    pImpl->result = j;
}


void ast::AstNodeSerializer::visit(ast::Scenario& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Scenario");
    Impl::serializeKwd(obj, j);
}


void ast::AstNodeSerializer::visit(ast::ScenarioOutline& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "ScenarioOutline");
    Impl::serializeKwd(obj, j);
}


void ast::AstNodeSerializer::visit(ast::Step& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Step");
}


void ast::AstNodeSerializer::visit(ast::TableCell& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "TableCell");
}


void ast::AstNodeSerializer::visit(ast::TableRow& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "TableRow");
}


void ast::AstNodeSerializer::visit(ast::Tag& obj)
{
    auto j = Impl::serializeAstNodeBase(obj, "Tag");
    j["name"] = obj.name;

    pImpl->result = j;
}
