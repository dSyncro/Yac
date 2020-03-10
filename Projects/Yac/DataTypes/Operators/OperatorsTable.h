#pragma once

#include <unordered_map>

#include <DataTypes/Operators/OperatorOverloads.h>

namespace Yac::DataTypes {

	class OperatorsTable final {

	public:

		void Overload(const UnaryOperatorOverload& overload, UnaryOperatorHandler handler) noexcept
		{
			_unaryOverloads[overload] = handler;
		}

		void Overload(const BinaryOperatorOverload& overload, BinaryOperatorHandler handler) noexcept
		{
			_binaryOverloads[overload] = handler;
		}

		bool Exists(const UnaryOperatorOverload& overload) const noexcept
		{
			std::unordered_map<UnaryOperatorOverload, UnaryOperatorHandler>::const_iterator it = _unaryOverloads.find(overload);
			return it != _unaryOverloads.end();
		}

		bool Exists(const BinaryOperatorOverload& overload) const noexcept
		{
			std::unordered_map<BinaryOperatorOverload, BinaryOperatorHandler>::const_iterator it = _binaryOverloads.find(overload);
			return it != _binaryOverloads.end();
		}

		UnaryOperatorHandler GetUnaryHandler(const UnaryOperatorOverload& overload) const noexcept
		{
			std::unordered_map<UnaryOperatorOverload, UnaryOperatorHandler>::const_iterator it = _unaryOverloads.find(overload);
			return it != _unaryOverloads.end() ? it->second : nullptr;
		}

		BinaryOperatorHandler GetBinaryHandler(const BinaryOperatorOverload& overload) const noexcept
		{
			std::unordered_map<BinaryOperatorOverload, BinaryOperatorHandler>::const_iterator it = _binaryOverloads.find(overload);
			return it != _binaryOverloads.end() ? it->second : nullptr;
		}

		Data* Call(const UnaryOperatorOverload& op, Yac::Api::Object* operand)
		{
			UnaryOperatorHandler handler = GetUnaryHandler(op);

			if (!handler) return nullptr;

			return handler(operand);
		}

		Data* Call(const BinaryOperatorOverload& op, Yac::Api::Object* a, Yac::Api::Object* b)
		{
			BinaryOperatorHandler handler = GetBinaryHandler(op);

			if (!handler) return nullptr;

			return handler(a, b);
		}

	private:

		std::unordered_map<UnaryOperatorOverload, UnaryOperatorHandler> _unaryOverloads;
		std::unordered_map<BinaryOperatorOverload, BinaryOperatorHandler> _binaryOverloads;

	};
}