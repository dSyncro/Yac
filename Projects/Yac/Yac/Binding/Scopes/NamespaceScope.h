#pragma once

#include <Yac/Core/Types/TypeTable.h>
#include <Yac/Core/BinaryOperatorTable.h>
#include <Yac/Core/NameTable.h>
#include <Yac/Binding/Scopes/Scope.h>

namespace Yac {

	struct NamespaceScope : Scope {

		NamespaceScope(NamespaceScope* parentNs = nullptr) 
			: Scope(ScopeType::Namespace, parentNs) {}

		std::unordered_map<std::string, NamespaceScope> namespaces;
		TypeTable types;
		BinaryOperatorTable binaryOperators;

		static NamespaceScope& getGlobal()
		{
			static NamespaceScope globalNamespace;
			return globalNamespace;
		}

		static TypeTable& getGlobalTypeTable() { return getGlobal().types; }
		static BinaryOperatorTable& getGlobalBinaryOperators() { return getGlobal().binaryOperators; }
		static NameTable& getGlobalNameTable() { return getGlobal().identifiers; }

	};

	inline void declareBuiltinTypes(NamespaceScope* scope)
	{
		scope->types.declare("int");
		scope->types.declare("uint");
		scope->types.declare("float");
		scope->types.declare("double");
	}

	inline void declareBuiltinBinaryOperators(NamespaceScope* scope)
	{
		const TypeSymbol& intType = scope->findTypeByName("int");

		scope->binaryOperators.declare(BBinaryOperator(intType, Operator::Addition, intType, intType));
		scope->binaryOperators.declare(BBinaryOperator(intType, Operator::Subtraction, intType, intType));
	}

}