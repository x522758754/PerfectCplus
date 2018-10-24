#pragma once
#include "ioRedirect.h"
#include <fstream>
//#include <ostream>
#include <iostream>

ioRedirect::ioRedirect()
{

}

ioRedirect::~ioRedirect()
{

}

void ioRedirect::run(int argc, char** argv)
{
	std::ifstream fin("../primer/ioRedirect/in.txt");
	std::ofstream fout("../primer/ioRedirect/out.txt");

	std::streambuf* cinbackup;
	std::streambuf* coutbackup;

	//rdbuf ÷ÿ∂®œÚ
	coutbackup = std::cout.rdbuf(fout.rdbuf());
	cinbackup = std::cin.rdbuf(fin.rdbuf());

	std::cout << "write:";
	char line[100];
	std::cin >> line;

	//ª÷∏¥
	std::cin.rdbuf(cinbackup);
	std::cout.rdbuf(coutbackup);
}
