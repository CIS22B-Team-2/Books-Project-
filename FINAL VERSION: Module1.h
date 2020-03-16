#pragma once

//Our abstract base class
#include <iostream>

class Module
{
public:
	Module()
	{
		std::cout << "\nA Module instance or instance of one of the inherited classes has just been created.\n\n";
	}

	virtual void driver() = 0;
};
