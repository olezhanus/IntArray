#include <iostream>
#include <vector>
#include "IntArray.h"

using namespace std;

void PrintArr(const IntArray &);

int main()
{
	try
	{
		IntArray arr;
		arr.resize(15);
		PrintArr(arr);
	}
	catch (const std::exception &e)
	{
		cout << e.what();
	}
	cout << "/////////////////////////////\n";
	try
	{
		IntArray arr(10, 5);
		PrintArr(arr);
	}
	catch (const std::exception &e)
	{
		cout << e.what();
	}
	cout << "/////////////////////////////\n";
	try
	{
		IntArray arr(-10, 3);
		arr.resize(15);
		PrintArr(arr);
	}
	catch (const std::exception &e)
	{
		cout << e.what();
	}
	cout << "/////////////////////////////\n";
	try
	{
		IntArray arr(10, 3);
		IntArray arr2(arr);
		PrintArr(arr);
		PrintArr(arr2);
	}
	catch (const std::exception &e)
	{
		cout << e.what();
	}
	cout << "/////////////////////////////\n";
	try
	{
		IntArray arr(10, 3);
		arr.resize(-15);
		PrintArr(arr);
	}
	catch (const std::exception &e)
	{
		cout << e.what();
	}
	return 0;
}

void PrintArr(const IntArray &arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << '\n';
	}
}
