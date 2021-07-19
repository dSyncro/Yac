#pragma once

#include <Yac/Core/Types/TypeTable.h>
#include <Yac/Core/BinaryOperatorTable.h>
#include <Yac/Core/NameTable.h>

namespace Yac {

	struct Namespace {

		Namespace(Namespace* parentNs = nullptr) : parent(parentNs) {}

		std::unordered_map<std::string, Namespace> namespaces;
		TypeTable types;
		NameTable names;
		BinaryOperatorTable binaryOperators;
		Namespace* parent;

		const TypeSymbol& findTypeOfName(const std::string& name) const
		{
			const Namespace* scope = this;
			do
			{
				const TypeSymbol& type = scope->names.getType(name);
				if (type != TypeSymbol::getInvalidTypeSymbol())
					return type;

				scope = scope->parent;
			} while (scope != nullptr);
			
			return TypeSymbol::getInvalidTypeSymbol();
		}

		static Namespace& getGlobal()
		{
			static Namespace globalNamespace;
			return globalNamespace;
		}

		static TypeTable& getGlobalTypeTable() { return getGlobal().types; }
		static BinaryOperatorTable& getGlobalBinaryOperators() { return getGlobal().binaryOperators; }
		static NameTable& getGlobalNameTable() { return getGlobal().names; }

	};

}