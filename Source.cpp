#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

int main()
{
	std::vector<int> v1(100); //выделена память под 100 лементов
	std::cout << std::endl << v1.capacity() << std::endl; // 100
	v1.push_back(1);
	std::cout << std::endl << v1.capacity() << std::endl; // 150
	for (auto i = 0; i < 49; i++)
	{
		v1.push_back(i);
	}
	std::cout << std::endl << v1.capacity() << std::endl; // 150
	v1.push_back(1);
	std::cout << std::endl << v1.capacity() << std::endl; //225
	// Вектор изначально выделяет ровно столько, сколько мы запросили.
	// При добавлении еще одного элемента, для которого не хватает места в исходном массиве,
	// вектор выделяет дополнительную память с коэффициентом 1.5



	std::vector<int> v2(99); //выделена память под 99 элементов
	std::cout << v2.capacity() << std::endl; //99
	v2.reserve(200); //довыделяет память под 200 элементов
	std::cout << v2.capacity() << std::endl; //200
	v2.push_back(1);
	std::cout << v2.capacity() << std::endl; //200
	// с помощью reserve мы уже можем самостоятельно указывать сколько памяти надо выделять
	// при прохождения этого порога, вектор уже дальше сам автоматически будет выделять память

	try
	{
		std::vector<int> v4(100);
		v4.reserve(99999999999); //выход за пределы
	}
	catch (std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}