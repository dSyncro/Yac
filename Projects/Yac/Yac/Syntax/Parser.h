#pragma once

#include <string>

#include <Yac/Core/Errors/ErrorList.h>
#include <Yac/Core/NumericBase.h>
#include <Yac/Core/Text/SourceText.h>
#include <Yac/Syntax/Expressions/Expression.h>
#include <Yac/Syntax/Keyword.h>
#include <Yac/Syntax/Operator.h>
#include <Yac/Syntax/Statements/Statement.h>
#include <Yac/Syntax/Token.h>

namespace Yac {

	class Parser {

	public:

		Parser(const Core::SourceText& source, Errors::ErrorList& errorList);

		Statement* Parse();

		const Errors::ErrorList& getErrors() const noexcept { return _errorList; }

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
		Statement* parseExpressionStatement() noexcept;
		Statement* parseVariableDeclaration(Keyword keyword = Keyword::Let) noexcept;

		Expression* parseInt(Core::NumericBase base = Core::NumericBase::Decimal) noexcept;
		Expression* parseUInt(Core::NumericBase base = Core::NumericBase::Decimal) noexcept;
		Expression* parseFloat(Core::NumericBase base = Core::NumericBase::Decimal) noexcept;
		Expression* parseDouble(Core::NumericBase base = Core::NumericBase::Decimal) noexcept;

		Expression* parseBoolean() noexcept;

		Expression* parseName() noexcept;
		Expression* parseStringLiteral() noexcept;
		Expression* parsePrefix() noexcept;
		Expression* parseParentheses() noexcept;

		Expression* parseExpression() noexcept;
		Expression* parseInstruction() noexcept;
		Expression* parseConditional() noexcept;
		Expression* parseFunctionCall() noexcept;
		Expression* parseFunctionCallOrName() noexcept;
		Expression* parsePrimaryExpression() noexcept;
		Expression* parseAssignmentExpression(AssignmentOperator op) noexcept;
		Expression* parseMathExpression(UIntT parentPrecedence = 0) noexcept;

		UIntT _position = 0;
		TokenList _tokens;
		Errors::ErrorList& _errorList;
	};
}