#include "AstNodeSerializer.h"

#include "AstNodes.h"

#include "json.hpp"

using json = nlohmann::json;

struct ast::AstNodeSerializer::Impl
{

};

ast::AstNodeSerializer::AstNodeSerializer() : pImpl(new ast::AstNodeSerializer::Impl) {}
ast::AstNodeSerializer::~AstNodeSerializer() {}


void ast::AstNodeSerializer::visit(const ast::Background& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::Comment& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::DataTable& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::DocString& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::Example& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::Feature& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::Scenario& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::ScenarioOutline& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::Step& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::TableCell& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::TableRow& obj)
{
    
}


void ast::AstNodeSerializer::visit(const ast::Tag& obj)
{
    
}

