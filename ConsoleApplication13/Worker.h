/** 
	@file
	@brief Файл класса Worker - Работник
	@author Lim0nchick
	@version 1.0
	@date Июнь 2016 года
*/

#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "Shell.h"
#include "Departament.h"
using namespace std;

class Worker	// Класс сотрудники 
{
	string name;
	vector <string> history;

public:
	Worker() : name("") {}

	Worker(string n) : name(n)
	{
		history.push_back("Was created as \"" + name + "\"");
	}

	string get_name()
	{
		return name;
	}

	string get_history(int i)
	{
		return history[i];
	}

	int get_history_size()
	{
		return history.size();
	}
	~Worker() {};
};
