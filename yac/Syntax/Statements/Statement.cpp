#include "Statement.h"

#include "VariableDeclaration.h"
#include "ExpressionStatement.h"

using namespace Yac::Syntax;

void Statement::Dispose(Statement* statement)
{
    switch (statement->type())
    {
        case StatementType::Expression: delete (ExpressionStatement*)statement; return;
        case StatementType::VariableDeclaration: delete (VariableDeclaration*)statement; return;
        case StatementType::None: default: return;
    }
}

Statement* Statement::Null() noexcept { return nullptr; }