#pragma once
#ifndef CLASSTASKER_H
#define CLASSTASKER_H
#include "functions.h"
using namespace std;
class Tasker {
public:
	char * taskCategory = new char[20], taskName[101];
	int taskHrs = 24, taskMins = 60;

	Tasker() {}
	void In() {
		int categoryMenuResult, timeInResult;
		cout << "Введите название задачи: ";
		cin.ignore();
		cin.getline(taskName, 101);

		cout << "Выберите категорию задачи: " << endl;
		categoryMenuResult = categoryMenu();
		switch (categoryMenuResult) {
		case 1: {
			taskCategory = "Личные";
			break;
		}
		case 2: {
			taskCategory = "Рабочие";
			break;
		}
		case 3: {
			taskCategory = "Покупки";
			break;
		}
		case 4: {
			taskCategory = "Другие";
			break;
		}
		default: {
			cout << "\n\tНЕВЕРНАЯ КОМАНДА! " <<
				"Выбрана категория «Другие»\n" << endl;
			taskCategory = "Другие";
		}
		}
		cout << "Если хотите задать время выполнения задачи, введите 1: ";
		cin >> timeInResult;
		switch (timeInResult) {
		case 1: {
			while (taskHrs < 0 || taskHrs > 23 || taskMins < 0 || taskMins > 59) {
				cout << "Введите время выполнения задачи: " << endl;
				cout << "\tЧасы: ";
				cin >> taskHrs;
				cout << "\tМинуты: ";
				cin >> taskMins;
				if (taskHrs < 0 || taskHrs > 23 || taskMins < 0 || taskMins > 59) {
					system("cls");
					cout << "\n\tНЕВЕРНЫЕ ДАННЫЕ!" << endl;
				}
			}
			break;
		}
		}
		system("cls");
	}
	void Out() {
		cout << "Задача: " << taskName << endl;
		cout << "   " << "Категория: " << taskCategory << endl;
		if (taskMins != 60 && taskHrs != 24) {
			if (taskMins < 10) {
				cout << "   " << "Время: " << taskHrs << ":" << "0" << taskMins << endl;
			}
			else {
				cout << "   " << "Время: " << taskHrs << ":" << taskMins << endl;
			}
		}
	cout << "=====================================" << endl;
	}
	friend istream & operator >> (istream & stream, Tasker & streamObj) {
		stream >> streamObj.taskCategory >> streamObj.taskName >> streamObj.taskHrs >> streamObj.taskMins;
		return stream; 
	}
	friend ostream & operator << (ostream & stream, const Tasker & streamObj) {
		stream << streamObj.taskCategory << " " << streamObj.taskName << " " << streamObj.taskHrs <<  " " << streamObj.taskMins;
		return stream;
	}
	/*const Tasker & Tasker::operator = (const Tasker & overlObj) {
		if (this == & overlObj) return *this;
		strcpy(taskCategory, overlObj.taskCategory);
		strcpy(taskName, overlObj.taskName);
		taskHrs = overlObj.taskHrs;
		taskMins = overlObj.taskMins;
		return *this;
	}*/
};
#endif