#pragma once

#include "AstNode.h"

namespace ast
{

class Background;
class Comment;
class DataTable;
class DocString;
class Example;
class Feature;
class Location;
class Scenario;
class ScenarioOutline;
class Step;
class TableCell;
class TableRow;
class Tag;

namespace core
{

class IAstNodeSerializer
{
public:
    
    virtual const string serialize(const Background& obj) = 0;
    virtual const string serialize(const Comment& obj) = 0;
    virtual const string serialize(const DataTable& obj) = 0;
    virtual const string serialize(const DocString& obj) = 0;
    virtual const string serialize(const Example& obj) = 0;
    virtual const string serialize(const Feature& obj) = 0;
    virtual const string serialize(const Location& obj) = 0;
    virtual const string serialize(const Scenario& obj) = 0;
    virtual const string serialize(const ScenarioOutline& obj) = 0;
    virtual const string serialize(const Step& obj) = 0;
    virtual const string serialize(const TableCell& obj) = 0;
    virtual const string serialize(const TableRow& obj) = 0;
    virtual const string serialize(const Tag& obj) = 0;

    virtual const string serialize(const AstNode& obj) = 0;

    virtual ~IAstNodeSerializer() {};  //TODO: not sure if necessary, maybe the default (non-virtual) dtor is enough
};

}
}
