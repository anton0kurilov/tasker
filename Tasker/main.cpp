#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include "classTasker.h"
#include "functions.h"
#include "classArray.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char doc[] = "tasks.txt";
	int menuMainResult = 1;
	Array <Tasker> Obj(doc);
	while (menuMainResult > 0) {
		menuMainResult = menuMain();
		switch (menuMainResult) {
		// Отображение задач
		case 1: {
			if (!Obj.taskOutOnScreen()) {
				cout << "\n\tВСЕ ЗАДАЧИ УДАЛЕНЫ!" << endl;
			}
			else {
				Obj.taskOutOnScreen();
			}
			break;
		}
		// Удаление задачи
		case 2: {
			Obj.taskOutOnScreen();
			int taskDeleteNum;
			cout << "Введите номер удаляемой задачи: ";
			cin >> taskDeleteNum;
			if (!Obj.taskDelete(taskDeleteNum)) {
				system("cls");
				cout << "\n\tЗАДАЧА НЕ НАЙДЕНА!" << endl;
			}
			else {
				Obj.taskDelete(taskDeleteNum);
				system("cls");
				cout << "\n\tЗАДАЧА УДАЛЕНА!" << endl;
			}
			Obj.taskSave(doc);
			break;
		}
		// Изменение задачи
		case 3: {
			Obj.taskOutOnScreen();
			int taskEditNum;
			cout << "Введите номер редактируемой задачи: ";
			cin >> taskEditNum;
			if (!Obj.taskEdit(taskEditNum)) {
				system("cls");
				cout << "\n\tЗАДАЧА НЕ НАЙДЕНА!" << endl;
			}
			else {
				Obj.taskEdit(taskEditNum);
			}
			Obj.taskSave(doc);
			break;
		}
		// Добавление задач
		case 4: {
			system("cls");
			cout << "Введите количество задач, которые вы хотите добавить: ";
			int taskAddNum;
			cin >> taskAddNum;
			Obj.taskAdd(taskAddNum);
			Obj.taskSave(doc);
			break;
		}
		case 5: {
			system("cls");
			int categoryMenuResult;
			cout << "Выберите категорию, которую нужно показать на экране: " << endl;
			categoryMenuResult = categoryMenu();
			if (categoryMenuResult > 0 && categoryMenuResult < 5) {
				if (Obj.taskCategoryOut(categoryMenuResult)) {
					Obj.taskCategoryOut(categoryMenuResult);
				}
				else {
					system("cls");
					cout << "\n\tЗАДАЧИ ДАННОЙ КАТЕГОРИИ НЕ НАЙДЕНЫ!" << endl;
				}
			}
			else {
				system("cls");
				cout << "\n\tКАТЕГОРИЯ НЕ НАЙДЕНА!" << endl;
			}
			break;
		}
		// Выход из программы
		case 0: {
			Obj.taskSave(doc);
			system("cls");
			exit();
			break;
		}
		// Неверная команда
		default: {
			Obj.taskSave(doc);
			system("cls");
			menuMainResult = 1;
			cout << "\n\tНЕВЕРНАЯ КОМАНДА!" << endl;
		}
		}
	}
	return 0;
}
