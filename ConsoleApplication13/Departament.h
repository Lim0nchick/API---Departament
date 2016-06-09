/** 
	@file
	@brief Файл класса Departament - Департамент
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
#include "Worker.h"
using namespace std;

class Department	// Класс Департамент
{
	string name_dep;
	vector <Worker*> workers;
public:
	Department() {}
	Department(string n) : name_dep(n) {}

	string get_dep()
	{
		return name_dep;
	}
	void set_dep(string n)
	{
		name_dep = n;
	}
	void add_worker(Worker* w)
	{
		workers.push_back(w);
	}
	Worker* get_worker(int i)
	{
		return workers[i];
	}
	void del_worker(int i)
	{
		workers.erase(workers.begin() + i);
	}
	int get_dep_size()
	{
		return workers.size();
	}
	~Department() {};
};