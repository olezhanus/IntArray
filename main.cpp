#include <iostream>
#include <ctime>
#include "IntArray.h"

using namespace std;

void PrintArr(const IntArray &);

int main()
{
	srand(time(0));
	cout << "////Testing IntArray:////\n\n";
	{
		IntArray a1(10, 1), a2;
		a2 = a1;
		for (size_t i = 0; i < a1.size(); ++i)
		{
			a1[i] = rand() % 5;
		}
		cout << "a1:\t"; PrintArr(a1);
		cout << "a2:\t"; PrintArr(a2);

		cout << "a1.find(3):\t" << a1.find(3) << '\n';

		a2.push_front(8);
		cout << "a2.push_front(8):\t"; PrintArr(a2);

		a2.push_back(8);
		cout << "a2.push_back(8):\t"; PrintArr(a2);

		a2.pop_back();
		cout << "a2.pop_back():\t\t"; PrintArr(a2);

		a2.pop_front();
		cout << "a2.pop_front():\t\t"; PrintArr(a2);

		a2.resize(15);
		cout << "a2.resize(15):\t\t"; PrintArr(a2);

		a2.resize(7);
		cout << "a2.resize(7):\t\t"; PrintArr(a2);

		a2.insert(3, a1);
		cout << "a2.insert(3, a1):\t"; PrintArr(a2);

		a2.insert(1, 30);
		cout << "a2.insert(1, 30):\t"; PrintArr(a2);

		a2.insert(16, 20, 0);
		cout << "a2.insert(16, 20, 0):\t"; PrintArr(a2);

		a2.erase(0);
		cout << "a2.erase(0):\t\t"; PrintArr(a2);

		a2.erase(1, 14);
		cout << "a2.erase(1, 14):\t"; PrintArr(a2);

		cout << "a2.empty():\t" << a2.empty() << '\n';

		cout << "a2.size():\t" << a2.size() << '\n';

		cout << "a2.capacity():\t" << a2.capacity() << '\n';

		a2.clear();
		cout << "a2.clear()" << '\n';

		cout << "a2.empty():\t" << a2.empty() << '\n';
	}


	cout << "\n\n////Testing exceptions:////\n\n";
	try
	{
		cout << "IntArray a1(-1):\t";
		IntArray a1(-1);
	}
	catch (const std::exception &e)
	{
		cout << e.what() << '\n';
	}
	try
	{
		IntArray a1(10);
		cout << "a1.resize(-3):\t\t";
		a1.resize(-3);
	}
	catch (const std::exception &e)
	{
		cout << e.what() << '\n';
	}
	try
	{
		IntArray a1(10);
		cout << "a1.insert(15, 1):\t";
		a1.insert(15, 1);
	}
	catch (const std::exception &e)
	{
		cout << e.what() << '\n';
	}
	try
	{
		IntArray a1(10);
		cout << "a1.erase(-1):\t\t";
		a1.erase(-1);
	}
	catch (const std::exception &e)
	{
		cout << e.what() << '\n';
	}
	try
	{
		IntArray a1(10);
		cout << "a1[10]:\t\t\t";
		a1[10];
	}
	catch (const std::exception &e)
	{
		cout << e.what() << '\n';
	}
	try
	{
		IntArray a1(10);
		cout << "a1[-1]:\t\t\t";
		a1[-1];
	}
	catch (const std::exception &e)
	{
		cout << e.what() << '\n';
	}
	return 0;
}




void PrintArr(const IntArray &arr)
{
	if (arr.empty())
	{
		cout << "Array is empty";
	}
	else
	{
		for (size_t i = 0; i < arr.size(); ++i)
		{
			cout << arr[i] << ' ';
		}
	}
	cout << '\n';
}
