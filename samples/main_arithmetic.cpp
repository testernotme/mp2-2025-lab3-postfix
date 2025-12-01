// реализация пользовательского приложения
#include "arithmetic.h"
#include<iostream>
int main()
{

	
	std::string s;
	std::cin >> s;
	TPostfix t("x");
	t.setVar("x",12);
	std::cout << t.solve();
	return 0;
}
