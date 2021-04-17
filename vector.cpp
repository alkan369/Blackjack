#pragma once
#include <iostream>
#include "vector.h"


template <typename T>
void Vector<T>::copy(const Vector<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new(std::nothrow) T[size];
	for (int i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
void Vector<T>::resize() {
	capacity = capacity * 2;
	T* temp = new (std::nothrow) T[capacity];
	for (int i = 0; i < size; i++) {
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

template <typename T>
T& Vector<T>::at(size_t i) {
	if (i < size) {
		return data[i];
	}
}

template <typename T>
Vector<T>::Vector() {
	size = 0;
	capacity = 8;
	data = new(std::nothrow) T[capacity];
}
template <typename T>
Vector<T>::Vector(size_t addCapacity) {
	size = 0;
	capacity = addCapacity;
	data = new(std::nothrow)T[capacity];
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copy(other);
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		delete[] data;
		copy(other);
	}
	return *this;
}
template <typename T>
Vector<T>::~Vector() {
	delete[] data;
}

template <typename T>
size_t Vector<T>::getSize()const {
	return size;
}

template <typename T>
size_t Vector<T>::getCapacity()const {
	return capacity;
}
template <typename T>
T Vector<T>::operator[](size_t i) const {
	return at(i);
}
template <typename T>
T& Vector<T>::operator[](size_t i) {
	return at(i);
}
template <typename T>
void Vector<T>::push_back(const T& add) {
	if (size == capacity) {
		resize();
	}
	data[size] = add;
	++size;
}

template <typename T>
void Vector<T>::pop() {
	delete[] data;
	data = new (std::nothrow) T[capacity];
	size = 0;
} 