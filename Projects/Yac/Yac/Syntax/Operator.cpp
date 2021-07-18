#include "Operator.h"

#include <Yac/Core/Base.h>

using namespace Yac;

std::string Yac::toString(Operator op)
{
	switch (op)
	{
		ENUM_ELEMENT_TO_STRING(Operator, Comma);
		ENUM_ELEMENT_TO_STRING(Operator, LogicalOr);
		ENUM_ELEMENT_TO_STRING(Operator, LogicalAnd);
		ENUM_ELEMENT_TO_STRING(Operator, BitwiseOr);
		ENUM_ELEMENT_TO_STRING(Operator, Xor);
		ENUM_ELEMENT_TO_STRING(Operator, BitwiseAnd);
		ENUM_ELEMENT_TO_STRING(Operator, EqualTo);
		ENUM_ELEMENT_TO_STRING(Operator, NotEqualTo);
		ENUM_ELEMENT_TO_STRING(Operator, LessThan);
		ENUM_ELEMENT_TO_STRING(Operator, LessEqualThan);
		ENUM_ELEMENT_TO_STRING(Operator, GreaterThan);
		ENUM_ELEMENT_TO_STRING(Operator, GreaterEqualThan);
		ENUM_ELEMENT_TO_STRING(Operator, RightShift);
		ENUM_ELEMENT_TO_STRING(Operator, Addition);
		ENUM_ELEMENT_TO_STRING(Operator, Subtraction);
		ENUM_ELEMENT_TO_STRING(Operator, Multiplication);
		ENUM_ELEMENT_TO_STRING(Operator, Division);
		ENUM_ELEMENT_TO_STRING(Operator, Modulo);
		ENUM_ELEMENT_TO_STRING(Operator, Identity);
		ENUM_ELEMENT_TO_STRING(Operator, Negation);
		ENUM_ELEMENT_TO_STRING(Operator, PreIncrement);
		ENUM_ELEMENT_TO_STRING(Operator, PreDecrement);
		ENUM_ELEMENT_TO_STRING(Operator, LogicalNot);
		ENUM_ELEMENT_TO_STRING(Operator, OneComplementary);
		ENUM_ELEMENT_TO_STRING(Operator, PostIncrement);
		ENUM_ELEMENT_TO_STRING(Operator, PostDecrement);
		default: return "Unknown";
	}
}

std::string Yac::toString(AssignmentOperator op)
{
	switch (op)
	{
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, Assign);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, Add);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, Subtract);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, Multiply);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, Divide);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, Modulo);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, Or);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, And);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, Xor);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, LeftShift);
		ENUM_ELEMENT_TO_STRING(AssignmentOperator, RightShift);
		default: return "Unknown";
	}
}

UIntT Yac::getOperatorPrecedence(Operator op)
{
	switch (op)
	{
		// Binary
		case Operator::Comma: return 0x1;
		case Operator::LogicalOr: return 0x2;
		case Operator::LogicalAnd: return 0x3;
		case Operator::BitwiseOr: return 0x4;
		case Operator::Xor: return 0x5;
		case Operator::BitwiseAnd: return 0x6;
		case Operator::EqualTo: return 0x7;
		case Operator::NotEqualTo: return 0x7;
		case Operator::LessThan: return 0x8;
		case Operator::LessEqualThan: return 0x8;
		case Operator::GreaterThan: return 0x8;
		case Operator::GreaterEqualThan: return 0x8;
		case Operator::LeftShift: return 0x9;
		case Operator::RightShift: return 0x9;
		case Operator::Addition: return 0xA;
		case Operator::Subtraction: return 0xA;
		case Operator::Multiplication: return 0xB;
		case Operator::Division: return 0xB;
		case Operator::Modulo: return 0xB;

			// Unary
		case Operator::Identity: return 0xC;
		case Operator::Negation: return 0xC;
		case Operator::PreIncrement: return 0xC;
		case Operator::PreDecrement: return 0xC;
		case Operator::LogicalNot: return 0xC;
		case Operator::OneComplementary: return 0xC;
		case Operator::PostIncrement: return 0xD;
		case Operator::PostDecrement: return 0xD;

			// Helper
		case Operator::Unknown:
		default: return 0;
	}
}

Operator Yac::toUnaryOperator(TokenType type)
{
	switch (type)
	{
		case TokenType::PlusSymbol: return Operator::Identity;
		case TokenType::MinusSymbol: return Operator::Negation;
		case TokenType::ExclamationMark: return Operator::LogicalNot;
		case TokenType::TildeSymbol: return Operator::OneComplementary;
		default: return Operator::Unknown;
	}
}

Operator Yac::toBinaryOperator(TokenType type)
{
	switch (type)
	{
		case TokenType::Comma: return Operator::Comma;
		case TokenType::DoublePipeSymbol: return Operator::LogicalOr;
		case TokenType::DoubleAndSymbol: return Operator::LogicalAnd;
		case TokenType::PipeSymbol: return Operator::BitwiseOr;
		case TokenType::CircumflexSymbol: return Operator::Xor;
		case TokenType::AndSymbol: return Operator::BitwiseAnd;
		case TokenType::DoubleEqualSymbol: return Operator::EqualTo;
		case TokenType::NotEqualSymbol: return Operator::NotEqualTo;
		case TokenType::LessSymbol: return Operator::LessThan;
		case TokenType::LessEqualSymbol: return Operator::LessEqualThan;
		case TokenType::GreaterSymbol: return Operator::GreaterThan;
		case TokenType::GreaterEqualSymbol: return Operator::GreaterEqualThan;
		case TokenType::ShiftLeftSymbol: return Operator::LeftShift;
		case TokenType::ShiftRightSymbol: return Operator::RightShift;
		case TokenType::PlusSymbol: return Operator::Addition;
		case TokenType::MinusSymbol: return Operator::Subtraction;
		case TokenType::StarSymbol: return Operator::Multiplication;
		case TokenType::SlashSymbol: return Operator::Division;
		default: return Operator::Unknown;
	}
}

AssignmentOperator Yac::toAssignmentOperator(TokenType type)
{
	switch (type)
	{
		case TokenType::EqualSymbol: return AssignmentOperator::Assign;
		case TokenType::PlusEqualSymbol: return AssignmentOperator::Add;
		case TokenType::MinusEqualSymbol: return AssignmentOperator::Subtract;
		case TokenType::StarEqualSymbol: return AssignmentOperator::Multiply;
		case TokenType::SlashEqualSymbol: return AssignmentOperator::Divide;
		case TokenType::PercentEqualSymbol: return AssignmentOperator::Modulo;
		case TokenType::PipeEqualSymbol: return AssignmentOperator::Or;
		case TokenType::AndEqualSymbol: return AssignmentOperator::And;
		case TokenType::CircumflexEqualSymbol: return AssignmentOperator::Xor;
		case TokenType::ShiftLeftSymbol: return AssignmentOperator::LeftShift;
		case TokenType::ShiftRightSymbol: return AssignmentOperator::RightShift;
		default: return AssignmentOperator::Unknown;
	}
}