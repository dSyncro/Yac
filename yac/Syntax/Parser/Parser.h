#pragma once

#include <string>

#include <yac/Syntax/Tokens/Token.h>
#include <yac/Syntax/Tokens/Keyword.h>
#include <yac/Syntax/Expressions/Expression.h>
#include <yac/Syntax/Expressions/Numeric/NumericBase.h>
#include <yac/Syntax/Expressions/Assignment/AssignmentOperator.h>
#include <yac/Syntax/Statements/Statement.h>
#include <yac/Errors/ErrorReporter.h>
#include <yac/Text/SourceText.h>

namespace Yac {
	namespace Syntax {

		class Parser {

		public:

			Parser(Yac::Text::SourceText source);

			Statement* Parse();

			Yac::Errors::ErrorList& errors() const noexcept { return _reporter.GetList(); }

		private:

			inline void Step(unsigned int offset = 1) noexcept { _position += offset; }

			const Token& ConsumeNext() noexcept;

			inline const Token& Current() const noexcept { return Peek(0); }
			inline const Token& Next() const noexcept { return Peek(1); }

			const Token& Peek(unsigned int offset) const noexcept;

			bool Match(TokenType type, unsigned int offset = 0) const noexcept;
			bool MatchNext(TokenType type) const noexcept;

			const Token& EndOfFile() const noexcept;
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
			Expression* ParsePrefix() noexcept;
			Expression* ParseParentheses() noexcept;

			Expression* ParseExpression() noexcept;
			Expression* ParseInstruction() noexcept;
			Expression* ParseConditional() noexcept;
			Expression* ParsePrimaryExpression() noexcept;
			Expression* ParseAssignmentExpression(AssignmentOperator op) noexcept;
			Expression* ParseMathExpression(unsigned int parentPrecedence = 0) noexcept;

			unsigned int _position = 0;
			std::vector<Token> _tokens;
			Yac::Errors::ErrorReporter _reporter;
		};

	}
}