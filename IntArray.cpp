#include "IntArray.h"

IntArray::IntArray(long long size, int number)
{
	if (size < 0)
	{
		throw std::bad_array_new_length();
	}
	_size = size;
	_capacity = 1;
	while (_capacity <= _size)
	{
		_capacity *= 2;
	}
	_data = new int[_capacity];
	for (size_t i = 0; i < _size; ++i)
	{
		_data[i] = number;
	}
}

IntArray::IntArray(const IntArray &other)
{
	_capacity = other._capacity;
	_size = other._size;
	_data = new int[_capacity];
	for (size_t i = 0; i < _size; ++i)
	{
		_data[i] = other._data[i];
	}
}

bool IntArray::empty() const
{
	return !_size;
}

long long IntArray::size() const
{
	return _size;
}

long long IntArray::capacity() const
{
	return _capacity;
}

void IntArray::push_front(int number)
{
	push_back(number);
	for (size_t i = _size - 1; i > 0; --i)
	{
		_data[i] ^= _data[i - 1];
		_data[i - 1] ^= _data[i];
		_data[i] ^= _data[i - 1];
	}
}

void IntArray::pop_front()
{
	for (size_t i = 0; i < _size - 1 ; ++i)
	{
		_data[i] ^= _data[i + 1];
		_data[i + 1] ^= _data[i];
		_data[i] ^= _data[i + 1];
	}
	pop_back();
}

void IntArray::push_back(int number)
{
	resize(_size + 1);
	_data[_size - 1] = number;
}

void IntArray::pop_back()
{
	_data[_size - 1] = 0;
	resize(_size - 1);
}

long long IntArray::find(int number) const
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (number == _data[i])
		{
			return i;
		}
	}
	return -1;
}

void IntArray::insert(long long index, int number)
{
	if (index < 0 || index > _size)
	{
		throw std::out_of_range("Out of range exception");
	}
	resize(_size + 1);
	for (size_t i = _size - 1; i > index; --i)
	{
		_data[i] = _data[i - 1];
	}
	_data[index] = number;
}

void IntArray::insert(long long first, long long last, int number)
{
	if (first < 0 || first > _size || last < first)
	{
		throw std::out_of_range("Out of range exception");
	}
	resize(_size + last - first);
	for (size_t i = _size - 1; i > last; --i)
	{
		_data[i] = _data[i - last + first - 1];
	}
	for (size_t i = first; i < last; ++i)
	{
		_data[i] = number;
	}
}

void IntArray::insert(long long index, const IntArray &array)
{
	if (index < 0 || index > _size)
	{
		throw std::out_of_range("Out of range exception");
	}
	resize(_size + array._size);
	for (size_t i = _size - 1; i > index; --i)
	{
		_data[i] = _data[i - array._size - 1];
	}
	for (size_t i = index; i < index + array._size; ++i)
	{
		_data[i] = array._data[i - index];
	}
}

void IntArray::erase(long long index)
{
	if (index < 0 || index >(_size - 1))
	{
		throw std::out_of_range("Out of range exception");
	}
	for (size_t i = index; i < _size - 1; ++i)
	{
		_data[i] = _data[i + 1];
	}
	resize(_size - 1);
}

void IntArray::erase(long long first, long long last)
{
	if (first < 0 || first >(_size - 1) || last < 0 || last >(_size - 1) || last < first)
	{
		throw std::out_of_range("Out of range exception");
	}
	for (size_t i = first; i < _size - 1; ++i)
	{
		_data[i] = _data[i + last - first + 1];
	}
	resize(_size - last + first);
}

void IntArray::clear()
{
	_size = 0;
	_capacity = 1;
	delete[] _data;
	_data = new int(_capacity);
}

void IntArray::resize(long long new_size)
{
	if (new_size < 0)
	{
		throw std::bad_array_new_length();
	}
	if (new_size == 0)
	{
		clear();
		return;
	}
	if (new_size == _size)
	{
		return;
	}
	int *new_data;
	long long new_capacity = _capacity;

	while (new_capacity / 2 > new_size)
	{
		new_capacity /= 2;
	}
	while (new_capacity <= new_size)
	{
		new_capacity *= 2;
	}
	if (new_capacity == _capacity)
	{
		for (size_t i = _size; i < new_size; ++i)
		{
			_data[i] = 0;
		}
	}
	else
	{
		_capacity = new_capacity;
		new_data = new int[new_capacity];
		for (size_t i = 0; i < new_size; ++i)
		{
			if (i < _size)
			{
				new_data[i] = _data[i];
			}
			else
			{
				new_data[i] = 0;
			}
		}
		delete[] _data;
		_data = new_data;
		new_data = nullptr;
	}
	_size = new_size;
}

IntArray &IntArray::operator=(const IntArray &right)
{
	delete[] _data;
	_capacity = right._capacity;
	_size = right._size;
	_data = new int[_capacity];
	for (size_t i = 0; i < _size; ++i)
	{
		_data[i] = right._data[i];
	}
	return *this;
}

int &IntArray::operator[](long long index) const
{
	if (index < 0 || index >= _size)
	{
		throw std::out_of_range("Out of range exception");
	}
	return _data[index];
}

IntArray::~IntArray()
{
	delete[] _data;
	_data = nullptr;
}
