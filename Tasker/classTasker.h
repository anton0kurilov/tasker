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
		cout << "������� �������� ������: ";
		cin.ignore();
		cin.getline(taskName, 101);

		cout << "�������� ��������� ������: " << endl;
		categoryMenuResult = categoryMenu();
		switch (categoryMenuResult) {
		case 1: {
			taskCategory = "������";
			break;
		}
		case 2: {
			taskCategory = "�������";
			break;
		}
		case 3: {
			taskCategory = "�������";
			break;
		}
		case 4: {
			taskCategory = "������";
			break;
		}
		default: {
			cout << "\n\t�������� �������! " <<
				"������� ��������� �������\n" << endl;
			taskCategory = "������";
		}
		}
		cout << "���� ������ ������ ����� ���������� ������, ������� 1: ";
		cin >> timeInResult;
		switch (timeInResult) {
		case 1: {
			while (taskHrs < 0 || taskHrs > 23 || taskMins < 0 || taskMins > 59) {
				cout << "������� ����� ���������� ������: " << endl;
				cout << "\t����: ";
				cin >> taskHrs;
				cout << "\t������: ";
				cin >> taskMins;
				if (taskHrs < 0 || taskHrs > 23 || taskMins < 0 || taskMins > 59) {
					system("cls");
					cout << "\n\t�������� ������!" << endl;
				}
			}
			break;
		}
		}
		system("cls");
	}
	void Out() {
		cout << "������: " << taskName << endl;
		cout << "   " << "���������: " << taskCategory << endl;
		if (taskMins != 60 && taskHrs != 24) {
			if (taskMins < 10) {
				cout << "   " << "�����: " << taskHrs << ":" << "0" << taskMins << endl;
			}
			else {
				cout << "   " << "�����: " << taskHrs << ":" << taskMins << endl;
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