#pragma once

#include <string>

#include <Errors/ErrorList.h>
#include <Syntax/Expressions/Expression.h>
#include <Syntax/Expressions/Assignment/AssignmentOperator.h>
#include <Syntax/Expressions/Numeric/NumericBase.h>
#include <Syntax/Statements/Statement.h>
#include <Syntax/Tokens/Keyword.h>
#include <Syntax/Tokens/Token.h>
#include <Text/SourceText.h>

namespace Yac::Syntax {

	class Parser {

	public:

		Parser(const Yac::Text::SourceText& source, Yac::Errors::ErrorList& errorList);

		Statement* Parse();

		const Yac::Errors::ErrorList& getErrors() const noexcept { return _errorList; }

	private:

		inline void Step(std::size_t offset = 1) noexcept { _position += offset; }

		const Token& Consume() noexcept;

		const Token& Current() const noexcept { return Peek(0); }
		const Token& Next() const noexcept { return Peek(1); }

		const Token& Peek(std::size_t offset) const noexcept;

		bool Match(TokenType type, std::size_t offset = 0) const noexcept;
		bool MatchNext(TokenType type) const noexcept;

		const Token& MatchAndConsume(TokenType type) noexcept;

		Statement* ParseStatement() noexcept;
		Statement* ParseBlockStatement() noexcept;
		Statement* ParseStatementKeyword() noexcept;
		Statement* ParseIfStatement() noexcept;
		Statement* ParseForStatement() noexcept;
		Statement* ParseWhileStatement() noexcept;
		Statement* ParseInstructionStatement() noexcept;
		Statement* ParseVariableDeclaration(Keyword keyword = Keyword::Let) noexcept;

		Expression* ParseInt(NumericBase base = NumericBase::Decimal) noexcept;
		Expression* ParseUInt(NumericBase base = NumericBase::Decimal) noexcept;
		Expression* ParseFloat(NumericBase base = NumericBase::Decimal) noexcept;
		Expression* ParseDouble(NumericBase base = NumericBase::Decimal) noexcept;

		Expression* ParseBoolean() noexcept;

		Expression* ParseIdentifier() noexcept;
		Expression* ParseStringLiteral() noexcept;
		Expression* ParsePrefix() noexcept;
		Expression* ParseParentheses() noexcept;

		Expression* ParseExpression() noexcept;
		Expression* ParseInstruction() noexcept;
		Expression* ParseConditional() noexcept;
		Expression* ParsePrimaryExpression() noexcept;
		Expression* ParseAssignmentExpression(AssignmentOperator op) noexcept;
		Expression* ParseMathExpression(unsigned int parentPrecedence = 0) noexcept;

		std::size_t _position = 0;
		TokenList _tokens;
		Yac::Errors::ErrorList& _errorList;
	};
}