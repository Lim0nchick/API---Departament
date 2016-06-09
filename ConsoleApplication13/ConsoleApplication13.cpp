/** 
	@file
	@brief Файл функции main()
	@author Lim0nchick
	@version 1.0
	@date Июнь 2016 года
*/
#include <stdlib.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "Departament.h"
#include "Worker.h"
#include "Shell.h"
using namespace std;


int main()
{
	Shell shell;
	int n;
	string command;
	while (command != "exit")
	{
		cout << "> ";
		cin >> command;

		if (command == "help")
		{
			cout << "For emplyee" << endl;
			cout << "addemp - add new employee" << endl;
			cout << "listemp - list of employers" << endl;
			cout << "delemp - delete employee" << endl;
			cout << "For departaments" << endl;
			cout << "add_dep - add new department" << endl;
			cout << "list_dep - list of departments" << endl;
			cout << "del_dep - delete department" << endl;
			cout << "add_dep_emp - add employee to department" << endl;
			cout << "list_dep_emp - list employees of department" << endl;
			cout << "search_emp_dep - search employee in departments" << endl;
			cout << "rename_dep - reform Department" << endl;
			cout << "move_emp_dep - move employee to new department" << endl;
		}
		// Действия с рабами
		/**
			@brief Активация команд
 		if (command == "addemp")	// Добавление нового сотрудника
			shell.addemp();

		if (command == "listemp")	// Вывод списка сотрудникова
			shell.listemp();

		if (command == "delemp")	// Увольнение сотрудника
			shell.delemp();

		// Команды с зонами и дертаментами
		if (command == "add_dep")		// Добавление нового департамента
			shell.add_Department();

		if (command == "list_dep")		// Вывод департаментов
			shell.list_Department();

		if (command == "del_dep")		// Удаление департамента
			shell.del_Department();

		if (command == "add_dep_emp")	// Добавление сотрудника в департаменте 
			shell.add_worker_dep();

		if (command == "list_dep_emp")	// Вывод сотрудников из одного департамента
			shell.list_dep_worker();

		if (command == "search_emp_dep") // Поиск сотрудника
			shell.search_worker_dep();

		if (command == "rename_dep")	// Переформирование департамента
			shell.rename_dep();

		if (command == "move_emp_dep")	// Перемещение сотрудника между департаментами
			shell.move_worker_dep();
	}
	return 0;
}