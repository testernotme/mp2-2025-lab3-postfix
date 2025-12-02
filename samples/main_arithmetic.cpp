// реализация пользовательского приложения
#include "arithmetic.h"
#include<iostream>
int main()
{

	
	std::string s;
	std::cin >> s;
	TPostfix t(s);
	std::cout << t.solve();
	return 0;
}
