#include "AstNodeSerializer.h"

#include "AstNodes.h"

#include "json.hpp"

using json = nlohmann::json;

struct ast::AstNodeSerializer::Impl
{

};

ast::AstNodeSerializer::AstNodeSerializer() : pImpl(new ast::AstNodeSerializer::Impl) {}
ast::AstNodeSerializer::~AstNodeSerializer() {}


void ast::AstNodeSerializer::visit(ast::Background& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::Comment& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::DataTable& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::DocString& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::Example& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::Feature& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::Scenario& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::ScenarioOutline& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::Step& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::TableCell& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::TableRow& obj)
{
    
}


void ast::AstNodeSerializer::visit(ast::Tag& obj)
{
    
}

