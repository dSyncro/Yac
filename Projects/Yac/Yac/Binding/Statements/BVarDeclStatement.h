#pragma once

#include <Yac/Syntax/Keyword.h>
#include <Yac/Binding/Expressions/BExpression.h>
#include <Yac/Binding/Statements/BStatement.h>
#include <Yac/Binding/Scopes/Scope.h>

namespace Yac {

	struct BVarDeclStatement final : BStatement {

		BVarDeclStatement(Keyword keyword, const std::string& identifier, BExpression* bInitializer, Scope* scope) 
			: BStatement(StatementType::VariableDeclaration, scope),
			name(identifier), initializer(bInitializer)
		{
			_scope->identifiers.declare(identifier, bInitializer->getType());
		}

		std::string name;
		BExpression* initializer;
	};

}