#pragma once
#include <exception>
#include <stdexcept>
class IntArray
{
public:
	IntArray(long long size = 0, int number = 0);
	IntArray(const IntArray &other);
	bool empty() const;
	long long size() const;
	long long capacity() const;
	void push_back(int number);
	void pop_back();
	long long find(int number) const;
	void insert(long long index, int number);
	void insert(long long first, long long last, int number);
	void insert(long long index, const IntArray &array);
	void erase(long long index);
	void erase(long long first, long long last);
	void clear();
	void resize(long long new_size);
	IntArray &operator=(const IntArray &right);
	int &operator[](long long index) const;
	~IntArray();
private:
	long long _size, _capacity;
	int *_data;
};

