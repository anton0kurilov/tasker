#pragma once
#ifndef CLASSARRAY_H
#define CLASSARRAY_H
template <class T>
class Array {
public:
	Array() {}
	~Array() {}
	Array(char *doc);
	Array(int itsSize);
	T & operator[](int offSet) { 
		return pType[offSet]; 
	}
	const T & operator[](int offSet) const { 
		return pType[offSet]; 
	}
	int GetSize() const { 
		return itsSize; 
	}
	void taskIn();
	void taskSave(char *doc);
	bool taskOutOnScreen();
	bool taskCategoryOut(int categoryMenuResult);
	bool taskDelete(int taskDeleteNum);
	bool taskEdit(int taskEditNum);
	void taskAdd(int taskAddNum);
private:
	T * pType;
	int itsSize;
};
// Метод ввода задач
template <class T>
void Array<T>::taskIn() {
	for (int i = 0; i < itsSize; i++) {
		pType[i].In();
	}
}
// Метод вывода задач на дисплей
template <class T>
bool Array<T>::taskOutOnScreen() {
	system("cls");
	for (int i = 0, j = 1; i < itsSize; i++, j++) {
		cout  << j << ". ";
		pType[i].Out();
	}
	if (itsSize < 1) {
		return false;
	}
	else {
		return true;
	}
}
// Метод сохранения задачи
template <class T>
void Array<T>::taskSave(char *doc) {
	ofstream taskSaveObj(doc);
	taskSaveObj << itsSize << endl;
	for (int i = 0; i < itsSize; i++) {
		taskSaveObj << pType[i] << endl;
	}
}
// Метод удаления задачи
template <class T>
bool Array<T>::taskDelete(int taskDeleteNum) {
	if (taskDeleteNum > 0 && taskDeleteNum <= itsSize) {
		for (int i = taskDeleteNum - 1; i < itsSize; i++) {
			pType[i] = pType[i + 1];
		}
		itsSize -= 1;
		return true;
	}
	else {
		return false;
	}
}
// Метод вывода задач определенной категории
template <class T>
bool Array<T>::taskCategoryOut(int categoryMenuResult) {
	system("cls");
	switch (categoryMenuResult) {
	case 1: {
		char tas[] = "Личные";
		for (int i = 0; i < itsSize; i++) {
			if (strcmp(pType[i].taskCategory, tas) == 0) {
				pType[i].Out();
				return true;
			}
			else {
				return false;
			}
		}
		break;
	}
	case 2: {
		char tas[] = "Рабочие";
		for (int i = 0; i < itsSize; i++) {
			if (strcmp(pType[i].taskCategory, tas) == 0) {
				pType[i].Out();
				return true;
			}
			else {
				return false;
			}
		}
		break;
	}
	case 3: {
		char tas[] = "Покупки";
		for (int i = 0; i < itsSize; i++) {
			if (strcmp(pType[i].taskCategory, tas) == 0) {
				pType[i].Out();
				return true;
			}
			else {
				return false;
			}
		}
		break;
	}
	case 4: {
		char tas[] = "Другие";
		for (int i = 0; i < itsSize; i++) {
			if (strcmp(pType[i].taskCategory, tas) == 0) {
				pType[i].Out();
				return true;
			}
			else {
				return false;
			}
		}
		break;
	} 
	default: {
		return false;
	}
	}
}
// Метод редактирования задачи
template <class T>
bool Array<T>::taskEdit(int taskEditNum) {
	if (taskEditNum > 0 && taskEditNum <= itsSize) {
		pType[taskEditNum - 1].In();
		return true;
	}
	else {
		return false;
	}
	
}
// Метод добавления задачи
template <class T>
void Array<T>::taskAdd(int taskAddNum) {
	T * p;
	p = new T[itsSize + taskAddNum];
	for (int i = 0; i < itsSize; i++) {
		p[i] = pType[i];
	}
	for (int i = itsSize; i < itsSize + taskAddNum; i++) {
		T taskAddObj;
		taskAddObj.In();
		p[i] = taskAddObj;
	}
	itsSize = itsSize + taskAddNum;
	pType = p;
}
template <class T>
Array<T>::Array(int size)
	: itsSize(size) {
	pType = new T[size];
}
template <class T>
Array<T>::Array(char * doc) {
	welcome();
	ifstream fileIn(doc);
	if (fileIn.is_open()) {
		fileIn >> itsSize;
		pType = new T[itsSize];
		for (int i = 0; i < itsSize; i++) {
			fileIn >> pType[i];
		}
	}
	else {
		cout << "Введите количество задач, которые вы хотите добавить: ";
		cin >> itsSize;
		pType = new T[itsSize];
		for (int i = 0; i < itsSize; i++) {
			T ArrayObj;
			ArrayObj.In();
			pType[i] = ArrayObj;

		}
	}
}
#endif
