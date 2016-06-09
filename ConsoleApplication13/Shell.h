/** 
	@file
	@brief Файл класса-оболочки Shell
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
#include "Departament.h"
#include "Worker.h"
using namespace std;

class Shell
{
	vector <Worker> workers;	/// Вектор класса рабочий
	vector <Department> departs;	/// Вектор класса подразделение

public:
	Shell() {}			/// Создание подразделения без параметров
	Shell(const Shell& o)		/// Создание подразделения c параметром 
	{
		// TO-DO: Construcor 
	}

	void addemp()	/// Добавление нового сотрудника
	{
		string n;
		cout << "Enter worker name:";
		cin >> n;
		workers.push_back(Worker(n));
	}
	void listemp()	/// Вывод списка сотрудников
	{
		cout << "Workers: \n";
		for (int i = 0; i < workers.size(); i++)
		{
			cout << workers[i].get_name() << " " << endl;
		}
	}

	void delemp()	/// Увольнение сотрудника
	{
		string n;
		cout << "Enter worker name:";
		cin >> n;
		for (int i = 0; i < workers.size(); i++)	// Удаление из вектора рабочих
		{
			if (workers[i].get_name() == n)
			{
				workers.erase(workers.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < departs.size(); i++)	// Удаление из списка подразделений
		{
			for (int j = 0; j < departs[i].get_dep_size(); j++)
			{
				if (departs[i].get_worker(j)->get_name() == n)
				{
					departs[i].del_worker(j);
					j--;
				}

			}
		}
	}
	void add_Department()	/// Добавление подразделения
	{
		string n;
		cout << "Enter name of Department:";
		cin >> n;
		departs.push_back(Department(n));

	}
	void del_Department()	/// Удаление подразделения
	{
		Department D;
		string n;
		cout << "Enter name of Department:";
		cin >> n;
		for (int i = 0; i < departs.size(); i++)
		{
			if (departs[i].get_dep() == n)
			{
				departs.erase(departs.begin() + i);
				i--;
			}
		}
	}
	void list_Department()	/// Список подразделений
	{
		cout << "Departments: \n";
		for (int i = 0; i < departs.size(); i++)
		{
			cout << departs[i].get_dep() << " " << endl;
		}
	}
	void add_worker_dep()	/// Добавление сотрудника в подразделение
	{
		string n;
		int a = -1;
		cout << "Enter worker name:";
		cin >> n;
		for (int i = 0; i < workers.size(); i++)
		{
			if (workers[i].get_name() == n)
			{
				a = i;
			}
		}
		if (a == -1)
		{
			cout << "Worker not found: 404" << endl;
			return;
		}
		int b = -1;
		cout << "Enter Department name:";
		cin >> n;
		for (int i = 0; i < departs.size(); i++)
		{
			if (departs[i].get_dep() == n)
			{
				b = i;
			}
		}
		if (b == -1)
		{
			cout << "Department not found: 404" << endl;
			return;
		}

		departs[b].add_worker(&workers[a]);
	}
	void list_dep_worker()	/// Список работников департамента
	{
		string n;
		int b = -1;
		cout << "Enter Department name:";
		cin >> n;
		for (int i = 0; i < departs.size(); i++)
		{
			if (departs[i].get_dep() == n)
			{
				b = i;
			}
		}
		if (b == -1)
		{
			cout << "Department not found: 404" << endl;
			return;
		}
		cout << "Workers in Department: \n";
		for (int i = 0; i < departs[b].get_dep_size(); i++)
		{
			cout << departs[b].get_worker(i)->get_name() << " " << endl;
		}

	}
	void search_worker_dep()	/// Поиск сотрудника в департаменте
	{
		string n;
		int a = -1;
		cout << "Enter worker name:";
		cin >> n;
		for (int i = 0; i < workers.size(); i++)
		{
			if (workers[i].get_name() == n)
			{
				a = i;
				cout << "Worker found in the company: " << n << endl;
			}
		}
		if (a == -1)
		{
			cout << "Worker not found" << endl;
			return;
		}
		for (int i = 0; i < departs.size(); i++)
		{

			for (int j = 0; j < departs[i].get_dep_size(); j++)
			{
				if (departs[i].get_worker(j)->get_name() == n)
				{
					cout << "Worker: " << n << " found in the Department: " << departs[i].get_dep() << endl;
				}
			}
		}
	}
	void rename_dep()	/// Переформирование департамента
	{
		string n, r;
		int b = -1;
		cout << "Enter to rename Department:";
		cin >> n;
		for (int i = 0; i < departs.size(); i++)
		{
			if (departs[i].get_dep() == n)
			{
				b = i;
				cout << "Enter new name Department: ";
				cin >> r;
				departs[i].set_dep(r);
			}
		}
		if (b == -1)
		{
			cout << "Department not found: 404" << endl;
			return;
		}

	}
	void move_worker_dep()	/// Перемещение работника между департаментами
	{
		string n, e;
		int a = -1;
		cout << "Enter worker name to move:";
		cin >> n;
		for (int i = 0; i < workers.size(); i++)
		{
			if (workers[i].get_name() == n)
			{
				a = i;
			}
		}
		if (a == -1)
		{
			cout << "Worker not found: 404" << endl;
			return;
		}
		int b = -1;
		cout << "Enter Department to move in: ";
		cin >> e;
		for (int i = 0; i < departs.size(); i++)
		{
			if (departs[i].get_dep() == e)
			{
				b = i;
			}
		}
		if (b == -1)
		{
			cout << "Department not found: 404" << endl;
			return;
		}
		int m = 0;
		for (int i = 0; i < departs.size(); i++)
		{

			for (int j = 0; j < departs[i].get_dep_size(); j++)
			{
				if (departs[i].get_worker(j)->get_name() == n)
				{
					m = i;
				}
			}
		}
		departs[b].add_worker(&workers[a]);
		departs[m].del_worker(a);
	}
};
