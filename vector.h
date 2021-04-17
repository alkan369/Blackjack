#pragma once


template <typename T>
class Vector {
	private:
		T* data;
		size_t size;
		size_t capacity;
		void copy(const Vector& other);
		void resize();
		T& at(size_t i);
	public:
		Vector();
		Vector(size_t);
		Vector(const Vector& other);
		Vector& operator=(const Vector& other);
		~Vector();
		size_t getSize()const;
		size_t getCapacity()const;
		T operator[](size_t) const;
		T& operator[](size_t);
		void push_back(const T&);
		void pop();
};