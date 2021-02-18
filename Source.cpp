#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

int main()
{
	std::vector<int> v1(100); //�������� ������ ��� 100 ��������
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
	// ������ ���������� �������� ����� �������, ������� �� ���������.
	// ��� ���������� ��� ������ ��������, ��� �������� �� ������� ����� � �������� �������,
	// ������ �������� �������������� ������ � ������������� 1.5



	std::vector<int> v2(99); //�������� ������ ��� 99 ���������
	std::cout << v2.capacity() << std::endl; //99
	v2.reserve(200); //���������� ������ ��� 200 ���������
	std::cout << v2.capacity() << std::endl; //200
	v2.push_back(1);
	std::cout << v2.capacity() << std::endl; //200
	// � ������� reserve �� ��� ����� �������������� ��������� ������� ������ ���� ��������
	// ��� ����������� ����� ������, ������ ��� ������ ��� ������������� ����� �������� ������

	try
	{
		std::vector<int> v4(100);
		v4.reserve(99999999999); //����� �� �������
	}
	catch (std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}