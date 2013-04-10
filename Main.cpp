#include <iostream>
#include "CDictionary.h"

int menu_a;
CDictionary English_Rus_Translate;

void main()
{
	///*************************************************************
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Header
	std::cout << "\n********************************************\n";
	std::cout << "*Programm \'Enlish-Russian Translate v1.0 \\о\'*";
	std::cout << "\n********************************************\n";
	//Menu
	std::cout << "*_____________________Menu__________________*\n\n";
	std::cout << "		1-Добавить\n";
	std::cout << "		2-Найти\n";
	std::cout << "		3-Вывести\n";
	std::cout << "		4-Удалить содержимое файла\n";
	std::cout << "		0-Выход\n";
	std::cout << "\n*___________________________________________*\n";	
	///*************************************************************

	//Условие для меню *Влитвление*
	do 
	{
	std::cin >> menu_a;
	//****************1-ADD***********
	if (menu_a==1) English_Rus_Translate.add();
	
	//****************2-FIND***********
		if (menu_a==2) 
		{
		char cWord[5];
		std::cout << "Введите имя индекса для поиска:\n";
		std::cin >> cWord;
		English_Rus_Translate.Find(cWord);
		}
		
	//****************3-OUT***********
if (menu_a==3) English_Rus_Translate.out();

	//****************4-DELETE***********
if (menu_a==4) English_Rus_Translate.deleteD();
	}
	while (menu_a!=0);

system("pause");
}
