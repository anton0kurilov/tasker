#pragma once
#ifndef CLASSARRAY_H
#define CLASSARRAY_H
template <class T>
class Array {
public:
	Array() {}
	~Array() {
		delete[] pType;
	}
	Array(char * address);
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
	void taskSave(char * address);
	bool taskOutOnScreen();
	bool taskCategoryOut(int categoryMenuResult);
	bool taskDelete(int taskDeleteNum);
	bool taskEdit(int taskEditNum);
	bool taskAdd(int taskAddNum);
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
// Метод вывода задач определенной категории
template <class T>
bool Array<T>::taskCategoryOut(int categoryMenuResult) {
	char * taskCategoryOut;
	int i = 0, j = 0;
	if (categoryMenuResult == 1) {
		taskCategoryOut = "Личные";
	}
	else if (categoryMenuResult == 2) {
		taskCategoryOut = "Рабочие";
	}
	else if (categoryMenuResult == 3) {
		taskCategoryOut = "Покупки";
	}
	else if (categoryMenuResult == 4) {
		taskCategoryOut = "Другие";
	}
	else {
		taskCategoryOut = "";
	}
	for (i; i < itsSize; i++) {
		if (strcmp(pType[i].taskCategory, taskCategoryOut) == 0) {
			j += 1;
			cout << j << ". ";
			pType[i].Out();
		}
	}
	if (j > 0) {
		return true;
	}
	else {
		return false;
	}
}

// Метод вывода задач на дисплей
template <class T>
bool Array<T>::taskOutOnScreen() {
	system("cls");
	for (int i = 0, j = 1; i < itsSize; i++, j++) {
		cout << j << ". ";
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
void Array<T>::taskSave(char * address) {
	ofstream taskSaveObj(address);
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
bool Array<T>::taskAdd(int taskAddNum) {
	if (taskAddNum > 20) {
		return false;
	}
	else {
		T * p;
		p = new T[itsSize + taskAddNum];
		for (int i = 0; i < itsSize; i++) {
			p[i] = pType[i];
		}
		for (int i = itsSize; i < itsSize + taskAddNum; i++) {
			p[i].In();
		}
		itsSize = itsSize + taskAddNum;
		pType = p;
		return true;
	}
}
template <class T>
Array<T>::Array(int size)
	: itsSize(size) {
	pType = new T[size];
}
template <class T>
Array<T>::Array(char * address) {
	welcome();
	ifstream fileIn(address);
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
			pType[i].In();
		}
	}
}
#endif
