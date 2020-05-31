#include <iostream>
#include "class.h"


int main()
{
	TString s1, s2;
	int n;
	char sep;
	std::cout << "Input s1: ";
	std::cin >> s1;
	std::cout << "S1 is : " << s1 << std::endl;
	std::cout << "Input s2: ";
	std::cin >> s2;
	std::cout << "s1 is : " << s2 << std::endl;
	std::cout << "s1 + s2 = " << s1+s2 << std::endl;

	if (s1 == s2)
		std::cout << "s1 = s2" << std::endl;
	else if (s1 < s2)
		std::cout << "s1 < s2" << std::endl;
	else if (s1 > s2)
		std::cout << "s1 > s2" << std::endl;

	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "s1's " << n + 1 << "th(st/nd/rd) element is " << s1[n] <<  std::endl;

	s2 = s2.rep(s2, n);
	std::cout << "s2 "<< n << " times is " << s2 << std::endl;


	std::cout << "Input separator: ";
	std::cin >> sep;
	TString* array = 0;
	array = s2.sep(sep);
	if (s2.lng() - 2 != s2.psnl(sep))
		n = s2.psnc(sep) + 1;
	else
		n = s2.psnc(sep);
	for (int i = 0; i < n; i++)
	{
		TString copy = array[i];
		std::cout << "Array: " << copy;
	}
}