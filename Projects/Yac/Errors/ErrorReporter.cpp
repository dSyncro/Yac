#include "ErrorReporter.h"

#include <Syntax/SyntaxRules.h>
#include <Text/TextSpan.h>

using namespace Yac::Syntax;
using namespace Yac::Errors;
using namespace Yac::Text;

void ErrorReporter::ReportUnexpectedToken(TokenType expected, TokenType found, const TextSpan& span) const noexcept
{
	std::string msg = "Expected <";
	msg.append(ToString(expected));
	msg.append("> token, <");
	msg.append(ToString(found));
	msg.append("> found");
	_list->Add(Error(msg, span));
}

void ErrorReporter::ReportUnknownToken(char c, const TextSpan& span) const noexcept
{
	std::string msg = "Found unknown token '";
	msg.append(std::string(1, c));
	msg.append("'");
	_list->Add(Error(msg, span));
}

void ErrorReporter::ReportNotABooleanLiteral(const std::string& text, const TextSpan& span) const noexcept
{
	std::string msg = "'";
	msg.append(text);
	msg.append("' is not a valid Boolean literal");
	_list->Add(Error(msg, span));
}