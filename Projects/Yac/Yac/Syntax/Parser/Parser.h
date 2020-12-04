#pragma once

#include <string>

#include <Yac/Errors/ErrorList.h>
#include <Yac/Syntax/Expressions/Expression.h>
#include <Yac/Syntax/Expressions/Assignment/AssignmentOperator.h>
#include <Yac/Syntax/Expressions/Numeric/NumericBase.h>
#include <Yac/Syntax/Statements/Statement.h>
#include <Yac/Syntax/Tokens/Keyword.h>
#include <Yac/Syntax/Tokens/Token.h>
#include <Yac/Text/SourceText.h>

namespace Yac::Syntax {

	class Parser {

	public:

		Parser(const Yac::Text::SourceText& source, Yac::Errors::ErrorList& errorList);

		Statement* Parse();

		const Yac::Errors::ErrorList& getErrors() const noexcept { return _errorList; }

	private:

		void step(UIntT offset = 1) noexcept { _position += offset; }

		const Token& consume() noexcept;

		const Token& current() const noexcept { return peek(0); }
		const Token& next() const noexcept { return peek(1); }

		const Token& peek(UIntT offset) const noexcept;

		bool match(TokenType type, UIntT offset = 0) const noexcept;
		bool matchNext(TokenType type) const noexcept;

		const Token& matchAndConsume(TokenType type) noexcept;

		Statement* parseStatement() noexcept;
		Statement* parseBlockStatement() noexcept;
		Statement* parseStatementKeyword() noexcept;
		Statement* parseIfStatement() noexcept;
		Statement* parseForStatement() noexcept;
		Statement* parseWhileStatement() noexcept;
		Statement* parseInstructionStatement() noexcept;
		Statement* parseVariableDeclaration(Keyword keyword = Keyword::Let) noexcept;

		Expression* parseInt(NumericBase base = NumericBase::Decimal) noexcept;
		Expression* parseUInt(NumericBase base = NumericBase::Decimal) noexcept;
		Expression* parseFloat(NumericBase base = NumericBase::Decimal) noexcept;
		Expression* parseDouble(NumericBase base = NumericBase::Decimal) noexcept;

		Expression* parseBoolean() noexcept;

		Expression* parseIdentifier() noexcept;
		Expression* parseStringLiteral() noexcept;
		Expression* parsePrefix() noexcept;
		Expression* parseParentheses() noexcept;

		Expression* parseExpression() noexcept;
		Expression* parseInstruction() noexcept;
		Expression* parseConditional() noexcept;
		Expression* parsePrimaryExpression() noexcept;
		Expression* parseAssignmentExpression(AssignmentOperator op) noexcept;
		Expression* parseMathExpression(UIntT parentPrecedence = 0) noexcept;

		UIntT _position = 0;
		TokenList _tokens;
		Yac::Errors::ErrorList& _errorList;
	};
}