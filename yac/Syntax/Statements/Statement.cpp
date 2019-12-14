#include "Statement.h"

#include "Statements.h"

#include "ExpressionStatement.h"

using namespace Yac::Syntax;

void Statement::Dispose(Statement* statement)
{
    if (!statement) return;

    switch (statement->type())
    {
        case StatementType::Expression: delete (ExpressionStatement*)statement; return;
        case StatementType::If: delete (IfStatement*)statement; return;
        case StatementType::While: delete (WhileStatement*)statement; return;
        case StatementType::For: delete (ForStatement*)statement; return;
        case StatementType::VariableDeclaration: delete (VariableDeclaration*)statement; return;
        case StatementType::None: default: delete statement; return;
    }
}

Statement* Statement::Null() noexcept { return nullptr; }