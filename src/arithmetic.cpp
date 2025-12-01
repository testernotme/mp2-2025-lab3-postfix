#include "arithmetic.h"
#include<math.h>
// реализация функций и классов для вычисления арифметических выражений

void TPostfix::convetr_tobackPol()
{
	TStack<Lexem*> theap(size);
	for (Lexem* t = (heap.see()); ; t = (heap.see()))
	{
		if (t->getType() == Oper) {

			if (t->getsubType() == rnd_brckt_end) {
				while (!(theap.is_empty()) && theap.see()->getsubType() != rnd_brckt_start)
				{
					backPol.push(theap.pop());

				}
				theap.pop(); // Начальная скобка
				heap.pop(); // Начальная скобка
			}else {
				while (!(theap.is_empty()) && theap.see()->getsubType() < t->getsubType() && theap.see()->getsubType() != rnd_brckt_start)
				{
					backPol.push(theap.pop());

				}
				theap.push(heap.pop());
			}
		}
		else
		{
			backPol.push(heap.pop());

		}
		if (heap.is_empty())
		{
			break;
		}
	}
	while (!theap.is_empty())
	{
		backPol.push(theap.pop());
	}
	backPol.reverse();
}

double TPostfix::doMath(double op1, subType t) {
	switch (t)
	{
	case umin:
		return -op1 ;
		break;
	case usin:
		return sin( op1) ; break;
	case ucos:
		return cos(op1) ; break;
	case utg:
		return tan(op1); break;
	case usqrt:
		return sqrt( op1); break;
	default:
		break;
	}
}

double TPostfix::doMath(double op1, double op2, subType t)
{
	switch (t)
	{
	case sum:
		return op1 + op2;
		break;
	case mul:
		return op1 * op2; break;
	case dev:
		return op1 / op2; break;
	case sub:
		return op1 - op2; break;
	default:
		break;
	}
}

void TPostfix::parse(std::string s)
{
	std::string t ="";
	for (int i = 0; i < s.size(); ++i)
	{

		if(is_oper(s[i])||isUnarOp(t+ s[i]))
		{	

			if (isUnarOp(t+s[i]) && (i == t.size() || is_oper(s[i-t.size() - 1]))) {
				heap.push(new operation(t+s[i]));
				t = "";
			}
			
			else if(is_oper(s[i])){
				if (t != "")heap.push(new variable(t)); t = "";
				heap.push(new operation(s[i]));
			}
			
		}else t += s[i];
	}
	if (t != "") heap.push(new variable(t));
	heap.reverse();
}

void TPostfix::setVar(std::string s, double data)
{

	TStack<Lexem*> theap(heap.StSize());
	while (!heap.is_empty())
	{
		if (heap.see()->getType() == Var) {
			if (heap.see()->getsubType() == vr && heap.see()->getName() == s) {
				heap.see()->setData(data);
			}
		}
		theap.push(heap.pop());
	}
	theap.reverse();
	heap = theap;
}

double TPostfix::solve()
{
	convetr_tobackPol();
	TStack<Lexem*> answ1(size);
	for (int i = 0; i < backPol.StSize(); )
	{
		if (backPol.see()->getsubType() > 1 && backPol.see()->getsubType()<7) {
			answ1.push(new variable(doMath(answ1.pop()->getData(),backPol.pop()->getsubType())));
		}
		else if(backPol.see()->getType() == Oper) {
			answ1.push(new variable(doMath(answ1.pop()->getData(), answ1.pop()->getData(), backPol.pop()->getsubType())));
		}
		else
		{
			answ1.push(backPol.pop());
		}
	}
	return answ1.pop()->getData();
}

TPostfix::TPostfix(std::string s)
{
	size = s.size();
	heap =  TStack<Lexem*>(size);
	parse(s);

	backPol = TStack<Lexem*>(heap.StSize());
}

TPostfix::~TPostfix()
{
}
