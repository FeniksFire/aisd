#include <iostream>
#include "PatternFinder.h"

void runKmp() {
	PatternFinder data;
	std::string text{0};
	std::string substring{0};
	
	std::cout << "Type string: ";
	
	std::cin >> text;
	
	std::cout << "Type substring that you want find: ";
	
	std::cin >> substring;
	
	std::cout << "KMP indexes are: ";
	
	for(auto i: data.KMP(text, substring))
		std::cout << i << " ";
	
	std::cout << "\nBoyer Moore indexes are: ";
	
	for(auto i: data.BoyerMoore(text, substring))
		std::cout << i << " ";
	
	std::cout << "\nKarp Rapin indexes are: ";
	
	for(auto i: data.KarpRabin(text, substring))
		std::cout << i << " ";
}

int main() {
	runKmp();
	return 0;
}