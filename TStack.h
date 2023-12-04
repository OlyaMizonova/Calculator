#pragma once
#include <iostream>
#include<string>

template <class T>
class TStack_a {
public:
	TStack_a(int mS = 10) { //конструктор
		maxSize = mS;
		if (mS < 0) {
			throw - 1;
		}
		pMem = new T[maxSize];
		indexOfTopElement = -1;
	}
	TStack_a(const TStack_a<T>& st) {  //конструктор копирования
		maxSize = st.maxSize;
		pMem = new T[maxSize];
		indexOfTopElement = st.indexOfTopElement;
		for (int i = 0; i < indexOfTopElement + 1; i++) {
			pMem[i] = st.pMem[i];
		}
	}
	~TStack_a() {  //деструктор
		delete[]pMem;
	}

	bool is_empty() {
		if (indexOfTopElement != -1)
			return false;
		return true;
	}
	bool is_full() {
		if (indexOfTopElement + 1 == maxSize) {
			return true;
		}
		return false;
	}

	T top() {
		if (!is_empty())
			return pMem[indexOfTopElement];
		throw "empty stack";
	}
	T pop() {
		if (is_empty()) {
			throw "stack is empty";
		}
		return pMem[indexOfTopElement--];
	}
	void push(T elem) {
		if (is_full()) {
			throw "stack overflow";
		}
		pMem[++indexOfTopElement] = elem;
	}
	void clear() {
		indexOfTopElement = -1;
	}

	friend std::ostream& operator>>(std::ostream& os, const TStack_a& st) {
		for (int i = 0; i <= st.indexOfTopElement; i++) {
			os << st.pMem[i] << ' ';
		}
		return os;
	}
private:
	T* pMem;
	int maxSize;
	int indexOfTopElement;
};