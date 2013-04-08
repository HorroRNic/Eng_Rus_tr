#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>

	int i,nk=1,k=0, menu_a;
	char tm[20];
	const int p=3;

	//Создание класса для Англо-русского словаря
	class Eng_Rus
{

	public:  //Открытый доступ класса
		
	/*  std::string indexT;
		std::string engT;
		std::string rusT; */

		char indexT[5];
		char engT[40];
		char rusT[60];

				//Функция вывода
		void clOutput(char *m)
{
	std::cout<<m;
}

				//Функция ввода
		char *clInput(char *s)
{
	std::cin>>s;
	return s;
}

					//Функция добавления слов в англо-русский словарь
						void add()
					 {
				FILE* f = fopen("Translater.txt","a+"); 
				if(f != NULL) 
				{

				for (i=0;i<nk;i++)
				{
					std::cout << "\nВведите индекс перевода:\n";
					//std::cin >> indexT;
					clInput(indexT);

					std::cout << "Введите Английское слово:\n";
					//std::cin >> engT;
					clInput(engT);

					std::cout << "Введите перевод \'Русский\':\n";
					//std::cin >> rusT;
					clInput(rusT);

				fprintf(f,"%s %s %s \n",indexT,engT,rusT);
				}
				fclose(f);
				}
				else printf("Невозможно открыть файл\n"); 
				fclose(f);
					 }

		
						//***********Функция для очистки файла************
void deleteD()
	 {
FILE* f = fopen("Translater.txt","w"); 
if(f != NULL) 
{
fclose(f);
}
else printf("Невозможно открыть файл\n"); 
fclose(f);
	 }

//Фуекция вывода всего словаря
void out()
{
//cout << "\n";
 
std::cout << "-------------------\n";
FILE* f = fopen("Translater.txt","r");
if(f != NULL) 
{ 
int rez=0;
do
{
	rez=fscanf(f,"%s %s %s \n",indexT,engT,rusT); 
	puts(indexT);
	puts(engT);
	puts(rusT);
}
while (rez!=EOF);

fclose(f); 
} 
else std::cout<<"Невозможно открыть файл\n";
fclose(f);
std::cout << "-------------------\n";
system("pause");
}



	//Поиск по словарю
	void Find(char word[5])
{
//cout << "\n";
 
std::cout << "-------------------\n";
FILE* f = fopen("Translater.txt","r");
if(f != NULL) 
{ 

	for(i=0;i < nk;i++) 
	{
				fscanf(f,"%s \n",indexT);
				///Warnning
				//Сделать цикл for для сравнения массива символов для поиска
				if ( (indexT[0]==word[0]))
					/*&& (indexT[1]==word[1]) 
					&& (indexT[2]==word[2]) 
					&& (indexT[3]==word[3]) 
					&& (indexT[4]==word[4]) ) */

				{
				//fscanf(f,"%s %s %s \n",indexT,engT,rusT); 
				puts(indexT);
				puts(engT);
				puts(rusT);
				};
	}

fclose(f); 
} 
else std::cout<<"Невозможно открыть файл\n";
fclose(f);
std::cout << "-------------------\n";
system("pause");
}
};

Eng_Rus English_Rus_Translate;




int main()
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
if (menu_a==2) {
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
return 0;

}
