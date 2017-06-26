#pragma once
#ifndef CLASSTASKER_H
#define CLASSTASKER_H
#include "functions.h"
class Tasker {
public:
	char taskCategory[20],  taskName[101];
	int taskHrs = 24, taskMins = 60;

	Tasker() {}
	void In() {
		int categoryMenuResult, timeInResult;
		cout << "Введите название задачи: ";
		cin.ignore();
		cin.getline(taskName, sizeof(taskName));
		cout << "Выберите категорию задачи: " << endl;
		categoryMenuResult = categoryMenu();
		switch (categoryMenuResult) {
		case 1: {
			strcpy(taskCategory, "Личные");
			break;
		}
		case 2: {
			strcpy(taskCategory, "Рабочие");
			break;
		}
		case 3: {
			strcpy(taskCategory, "Покупки");
			break;
		}
		case 4: {
			strcpy(taskCategory, "Другие");
			break;
		}
		default: {
			cout << "\n\tНЕВЕРНАЯ КОМАНДА! " <<
				"Выбрана категория «Другие»\n" << endl;
			strcpy(taskCategory, "Другие");
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
					cout << "\n\tНЕВЕРНЫЕ ДАННЫЕ!\n" << endl;
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
		stream >> streamObj.taskCategory;
		stream.ignore();
		stream.getline(streamObj.taskName, sizeof(streamObj.taskName));
		stream.sync();
		stream >> streamObj.taskHrs >> streamObj.taskMins;
		return stream; 
	}
	friend ostream & operator << (ostream & stream, const Tasker & streamObj) {
		stream << streamObj.taskCategory << endl; 
		stream << streamObj.taskName << endl;
		stream << streamObj.taskHrs << " " << streamObj.taskMins << "\n";
		return stream;
	}
};
#endif
