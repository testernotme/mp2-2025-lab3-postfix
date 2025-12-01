#include "Lexem.h"

double variable::getData() { return data; }

std::string variable::getName()
{
	return name;
}

variable::variable(double d) {
	data = d; type = cnst;
}
variable::variable(std::string s) {
	if (s == "pi") {
		type = cnst;
		data = 3.14159265358979323846;
	}
	else if (s == "e") {
		type = cnst;
		data = 2.71828182845904523536;
	}
	else if (is_digit(s)) {
		type = cnst;
		data = std::stod(s);
	}
	else
	{
		type = vr;
		name = s;
	}
}
Type variable::getType() {
	return Var;
}
subType variable::getsubType() {
	return type;
}
void variable::setData(double t) { data = t; };
variable::~variable() { data = 0; }


double operation::getData() { return 0.0; }
void operation::setData(double t) { ; }
operation::operation(std::string s) {
	if (s == "-")
	{
		t = umin;
	}
	else if (s == "tg") { t = utg; }
	else if (s == "sqrt") { t = usqrt; }
	else if (s == "sin") { t = usin; }
	else if (s == "cos") { t = ucos; }

}
std::string operation::getName() { return ""; }
operation::operation(char c) {
	switch (c)
	{
	case '(':
		t = rnd_brckt_start; break;
	case ')':
		t = rnd_brckt_end; break;
	case '+':
		t = sum; break;
	case '*':
		t = mul; break;
	case '/':
		t = dev; break;
	case '-':
		t = sub; break;
	default:
		break;
	}
}
Type operation::getType() {
	return Oper;
}
subType operation::getsubType() { return t; }
