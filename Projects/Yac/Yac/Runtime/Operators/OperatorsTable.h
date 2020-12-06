#pragma once

#include <unordered_map>

#include "OperatorOverloads.h"

namespace Yac::Runtime {

	class OperatorsTable final {

	public:

		void overload(const UnaryOperatorOverload& overload, UnaryOperatorHandler handler) noexcept
		{
			_unaryOverloads[overload] = handler;
		}

		void overload(const BinaryOperatorOverload& overload, BinaryOperatorHandler handler) noexcept
		{
			_binaryOverloads[overload] = handler;
		}

		bool exists(const UnaryOperatorOverload& overload) const noexcept
		{
			std::unordered_map<UnaryOperatorOverload, UnaryOperatorHandler>::const_iterator it = _unaryOverloads.find(overload);
			return it != _unaryOverloads.end();
		}

		bool exists(const BinaryOperatorOverload& overload) const noexcept
		{
			std::unordered_map<BinaryOperatorOverload, BinaryOperatorHandler>::const_iterator it = _binaryOverloads.find(overload);
			return it != _binaryOverloads.end();
		}

		UnaryOperatorHandler getHandler(const UnaryOperatorOverload& overload) const noexcept
		{
			std::unordered_map<UnaryOperatorOverload, UnaryOperatorHandler>::const_iterator it = _unaryOverloads.find(overload);
			return it != _unaryOverloads.end() ? it->second : nullptr;
		}

		BinaryOperatorHandler getHandler(const BinaryOperatorOverload& overload) const noexcept
		{
			std::unordered_map<BinaryOperatorOverload, BinaryOperatorHandler>::const_iterator it = _binaryOverloads.find(overload);
			return it != _binaryOverloads.end() ? it->second : nullptr;
		}

		VariableData call(const UnaryOperatorOverload& op, Yac::Api::Object* operand)
		{
			UnaryOperatorHandler handler = getHandler(op);
			if (!handler) return VariableData();
			return handler(operand);
		}

		VariableData call(const BinaryOperatorOverload& op, Yac::Api::Object* a, Yac::Api::Object* b)
		{
			BinaryOperatorHandler handler = getHandler(op);
			if (!handler) return VariableData();
			return handler(a, b);
		}

	private:

		std::unordered_map<UnaryOperatorOverload, UnaryOperatorHandler> _unaryOverloads;
		std::unordered_map<BinaryOperatorOverload, BinaryOperatorHandler> _binaryOverloads;

	};
}