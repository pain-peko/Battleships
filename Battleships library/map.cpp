//map.cpp

#include "map.h"
#include <iostream>

Map map; //���������� ����������

Map::Map()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			ship_on_map[i][j] = 0;
		}
	}
}

void Map::Set_ship(Ship &ship, int Ox, int Oy, bool vertically) /*�����, ����� ����� ������� ������ ������� ����� � ���������������� �������� � ���� ������ � ���� �� �����������
																��� �������������. ����� �� ������� ������ ����� � ������ ������ ���������� �������, �� ����������� ��������� ���������
																������ �����������\�������������, � ����� ��������� �����, ��������� ���������� � ���� ����� � ��� ������*/
{
	//�������� �� ���������� ��������, ������������� ��� ��������
	/*
	for (int i = 0;i<3; i++)
	{
		for (int j = 0;j<3; j++)
		{
			if (Ox != 1 || Ox != 8 || Oy != 1 || Oy != 8)
			{
				if (ship_on_map[Ox - 1 - 1 + i][Oy - 1 - 1 + j] != 0)
				{
					std::cout << "ERROR, YOU CANT PLACE YOUR SHIP THERE, BECAUSE ANOTHER SHIP IS VERY CLOSE\n";
				}
			}
		}
	}
	*/

	//��������� ������� �� �����, �������� ������� ����
	ship_on_map[Ox - 1][Oy - 1] = &ship;
	if (vertically == false)
	{
		int a = 0; //�������, ����� ��������� ��������� �������, ����� ������ ����� ������� �� �������
		for (int i = 1;i <ship.Get_size_of_ship(); i++)
		{
			if (Ox + i <= length)
			{
				ship_on_map[Ox - 1 + i][Oy - 1] = &ship;
				a++;
			}
			else if (Ox + i > length)
			{
				ship_on_map[Ox - 1 - i + a][Oy - 1] = &ship;
			}
		}
	}
	else if (vertically == true)
	{
		int a = 0; //�������, ����� ��������� ��������� �������, ����� ������ ����� ������� �� �������
		for (int i = 1; i < ship.Get_size_of_ship(); i++)
		{
			if (Oy + i <= height)
			{
				ship_on_map[Ox - 1][Oy - 1 + i] = &ship;
				a++;
			}
			else if (Oy + i > height)
			{
				ship_on_map[Ox - 1][Oy - 1 - i + a] = &ship;
			}
		}
	}

}
Ship* Map::Get_ship(int Ox, int Oy)
{
	return ship_on_map[Ox - 1][Oy - 1];
}