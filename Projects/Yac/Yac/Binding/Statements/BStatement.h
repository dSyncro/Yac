#pragma once

#include <Yac/Core/Types/TypeSymbol.h>
#include <Yac/Syntax/Statements/StatementType.h>
#include <Yac/Binding/Scopes/Scope.h>

namespace Yac {

	struct BStatement {

		virtual ~BStatement() = default;

		StatementType getStatementType() const noexcept { return _statementType; }
		Scope* getScope() const noexcept { return _scope; }

	protected:

		BStatement(StatementType statementType, Scope* scope)
			: _statementType(statementType), _scope(scope) { }

		StatementType _statementType;
		Scope* _scope;

	};

}