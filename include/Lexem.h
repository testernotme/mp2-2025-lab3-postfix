#pragma once
#include <string>
#include <iostream>
inline  bool is_digit(std::string s) {
	for (int i = 0; i < s.size(); i++)
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == 46)) return false;
	}
	return true;
}
inline bool is_oper(char s) {
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')') {
		return true;
	}
	return false;
}inline bool isUnarOp(std::string s) {
	if (s == "-" || s == "sin" || s == "cos" || s == "tg" || s == "sqrt") {
		return true;
	}
	return false;
}
enum Type
{
	Oper = 0,
	UnOper = 1,
	Var = 2
};
enum subType
{
	cnst = 100,
	vr = 110,
	rnd_brckt_start = 0,
	rnd_brckt_end = 1,
	umin = 2,
	usin = 3,
	ucos = 4,
	utg = 5,
	usqrt = 6,
	mul = 7,
	dev = 8,
	sub = 9,
	sum = 10,
};
class Lexem
{
public:
	virtual Type getType() = 0;
	virtual std::string getName() = 0;
	virtual double getData() = 0;
	virtual void setData(double t) = 0;
	virtual subType getsubType() = 0;
	virtual ~Lexem() = default;
};
class variable : public Lexem { // тип перемменая 
	subType type;
	std::string name;
	double data;
public:
	double getData();
	std::string getName();
	variable(double d);
	variable(std::string s);
	Type getType();
	subType getsubType();
	void setData(double t);
	~variable();
};
class operation : public Lexem { // тип операция 
	subType t;
public:
	double getData();
	std::string getName();
	void setData(double t);
	operation(std::string s); //конструктор для бинарная операция
	operation(char c); //конструктор для унарная операция
	Type getType();
	subType getsubType();
};
