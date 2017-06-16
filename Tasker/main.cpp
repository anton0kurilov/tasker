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
		// ����������� �����
		case 1: {
			if (!Obj.taskOutOnScreen()) {
				cout << "\n\t��� ������ �������!" << endl;
			}
			else {
				Obj.taskOutOnScreen();
			}
			break;
		}
		// �������� ������
		case 2: {
			Obj.taskOutOnScreen();
			int taskDeleteNum;
			cout << "������� ����� ��������� ������: ";
			cin >> taskDeleteNum;
			if (!Obj.taskDelete(taskDeleteNum)) {
				system("cls");
				cout << "\n\t������ �� �������!" << endl;
			}
			else {
				Obj.taskDelete(taskDeleteNum);
				system("cls");
				cout << "\n\t������ �������!" << endl;
			}
			Obj.taskSave(doc);
			break;
		}
		// ��������� ������
		case 3: {
			Obj.taskOutOnScreen();
			int taskEditNum;
			cout << "������� ����� ������������� ������: ";
			cin >> taskEditNum;
			if (!Obj.taskEdit(taskEditNum)) {
				system("cls");
				cout << "\n\t������ �� �������!" << endl;
			}
			else {
				Obj.taskEdit(taskEditNum);
			}
			Obj.taskSave(doc);
			break;
		}
		// ���������� �����
		case 4: {
			system("cls");
			cout << "������� ���������� �����, ������� �� ������ ��������: ";
			int taskAddNum;
			cin >> taskAddNum;
			Obj.taskAdd(taskAddNum);
			Obj.taskSave(doc);
			break;
		}
		case 5: {
			system("cls");
			int categoryMenuResult;
			cout << "�������� ���������, ������� ����� �������� �� ������: " << endl;
			categoryMenuResult = categoryMenu();
			if (categoryMenuResult > 0 && categoryMenuResult < 5) {
				if (Obj.taskCategoryOut(categoryMenuResult)) {
					Obj.taskCategoryOut(categoryMenuResult);
				}
				else {
					system("cls");
					cout << "\n\t������ ������ ��������� �� �������!" << endl;
				}
			}
			else {
				system("cls");
				cout << "\n\t��������� �� �������!" << endl;
			}
			break;
		}
		// ����� �� ���������
		case 0: {
			Obj.taskSave(doc);
			system("cls");
			exit();
			break;
		}
		// �������� �������
		default: {
			Obj.taskSave(doc);
			system("cls");
			menuMainResult = 1;
			cout << "\n\t�������� �������!" << endl;
		}
		}
	}
	return 0;
}
