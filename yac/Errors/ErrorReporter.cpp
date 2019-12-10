#include "ErrorReporter.h"

#include <yac/Syntax/SyntaxRules.h>

using namespace Yac::Syntax;
using namespace Yac::Errors;
using namespace Yac::Text;

void ErrorReporter::ReportUnexpectedToken(TokenType expected, TokenType found, const TextSpan& span)
{
	std::string msg = "Expected <";
	msg.append(ToString(expected));
	msg.append("> token, <");
	msg.append(ToString(found));
	msg.append("> found");
	_list->Add(Error(msg, span));
}

void ErrorReporter::ReportUnknownToken(char c, const TextSpan& span)
{
	std::string msg = "Found unknown token '";
	msg.append(std::string(1, c));
	msg.append("'");
	_list->Add(Error(msg, span));
}