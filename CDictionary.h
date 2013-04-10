#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
//**********************************************************
/// VbloodV оформил... 
/// vbloodv дома буду делать поиск по префексу, если есть идеи реализации набрасай плиз.
//**********************************************************
	int i,k=0;
	char indexT[5];
	char wordsEng[40];
	char wordsRus[60];

//Создание класса для Англо-русского словаря
	class CDictionary
	{
	public: 	//Открытый доступ класса
		~CDictionary(){}; //Деструктор
	void add(); 
	void out();
	void deleteD();
	void Find(char word[5]);
	};


	void CDictionary::add()
{
FILE* f = fopen("Translater.txt","a+"); 
	if(f != NULL) 
	{
		std::cout << "\nВведите индекс перевода:\n";
		std::cin >> indexT;
		std::cout << "Введите Английское слово:\n";
		std::cin >> wordsEng;
		std::cout << "Введите перевод \'Русский\':\n";
		std::cin >> wordsRus;
		fprintf(f,"%s %s %s \n",indexT,wordsEng,wordsRus);
	fclose(f);
	}
	else printf("Невозможно открыть файл\n"); 
	fclose(f);
}

	void CDictionary::deleteD()
{
FILE* f = fopen("Translater.txt","w"); 
	if(f != NULL) 
	{
	fclose(f);
	}
else printf("Невозможно открыть файл\n"); 
fclose(f);
}

	void CDictionary::out()
{
std::cout << "-------------------\n";
FILE* f = fopen("Translater.txt","r");
	if(f != NULL) 
	{ 
	int rez=0;
		do
		{
		rez=fscanf(f,"%s %s %s \n",indexT,wordsEng,wordsRus); 
		puts(indexT);
		puts(wordsEng);
		puts(wordsRus);
		}
		while (rez!=EOF);

	fclose(f); 
	} 
else std::cout<<"Невозможно открыть файл\n";
fclose(f);
std::cout << "-------------------\n";
system("pause");
}

	void CDictionary::Find(char word[5])
{
std::cout << "-------------------\n";
FILE* f = fopen("Translater.txt","r");
	if(f != NULL) 
	{ 
				fscanf(f,"%s \n",indexT);
				if ( (indexT[0]==word[0]))
					/*&& (indexT[1]==word[1]) 
					&& (indexT[2]==word[2]) 
					&& (indexT[3]==word[3]) 
					&& (indexT[4]==word[4]) ) */
				{
				puts(indexT);
				puts(wordsEng);
				puts(wordsRus);
				}
	fclose(f); 
	} 
else std::cout<<"Невозможно открыть файл\n";
fclose(f);
std::cout << "-------------------\n";
system("pause");
}