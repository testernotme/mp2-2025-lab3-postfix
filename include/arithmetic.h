// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#include "stack.h"
#include "Lexem.h"
class TPostfix {
	size_t size;
	TStack<Lexem*> heap;
	TStack<Lexem*> backPol;
	void convetr_tobackPol();
	double doMath(double op1, double op2, subType t);// выполнение дл€ бинарных опреаторов
	double doMath(double op1, subType t); // выполнение дл€ унарных опреаторов
public:
	void parse(std::string s);
	void setVar(std::string s, double data);
	double solve();
	TPostfix(std::string s);
	~TPostfix();
};