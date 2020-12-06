#include "Command.h"

#include <Yac/Syntax/Lexer.h>

using namespace Yac::Core;
using namespace Yac::Errors;
using namespace Yac::Syntax;

Command::Command(const std::string& command, const ParameterList& parameters) : _cmd(command), _params(parameters) {}

Command Command::parse(const std::string& line) noexcept
{
	std::string cmd = "";
	ParameterList params;

	std::string actualLine = line.substr(1);
	SourceText source = SourceText(actualLine);
	ErrorList errorList = ErrorList();
	Lexer lexer = Lexer(source, errorList);

	TokenList tokens;

	Token currentToken;
	do
	{
		currentToken = lexer.consumeNext();
		if (currentToken.getType() != TokenType::Whitespace && currentToken.getType() != TokenType::Newline)
			tokens.push_back(currentToken);
	} while (currentToken.getType() != TokenType::EndOfFile);

	UIntT i = 0;
	TokenType currentType = TokenType::Unknown;

	// Find command
	// First token is '#', Last is EoF
	for (i; i < tokens.size() - 1; i++)
	{
		currentToken = tokens[i];
		currentType = currentToken.getType();

		if (!isWord(currentType))
			errorList.reportUnexpectedToken(TokenType::StringLiteral, currentType, currentToken.getSpan());
		else
		{
			cmd = currentToken.getText();
			i++;
			break;
		}
	}

	if (cmd.empty())
		errorList.reportUnexpectedToken(TokenType::Identifier, TokenType::EndOfFile, currentToken.getSpan());

	// Collect params
	// Last is EoF
	for (i; i < tokens.size() - 1; i++)
	{
		currentToken = tokens[i];
		TokenType currentType = currentToken.getType();

		if (isWord(currentType) || isNumeric(currentType))
		{
			params.push_back(currentToken.getText());
			continue;
		}
		else
			errorList.reportUnexpectedToken(TokenType::StringLiteral, currentType, currentToken.getSpan());
	}

	if (errorList.any())
		return Command("", {});

	return Command(cmd, params);
}
