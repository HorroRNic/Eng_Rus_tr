#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>

	int i,nk=1,k=0, menu_a;
	char tm[20];
	const int p=3;

	//�������� ������ ��� �����-�������� �������
	class Eng_Rus
{

	public:  //�������� ������ ������
		
	/*  std::string indexT;
		std::string engT;
		std::string rusT; */

		char indexT[5];
		char engT[40];
		char rusT[60];

				//������� ������
		void clOutput(char *m)
{
	std::cout<<m;
}

				//������� �����
		char *clInput(char *s)
{
	std::cin>>s;
	return s;
}

					//������� ���������� ���� � �����-������� �������
						void add()
					 {
				FILE* f = fopen("Translater.txt","a+"); 
				if(f != NULL) 
				{

				for (i=0;i<nk;i++)
				{
					std::cout << "\n������� ������ ��������:\n";
					//std::cin >> indexT;
					clInput(indexT);

					std::cout << "������� ���������� �����:\n";
					//std::cin >> engT;
					clInput(engT);

					std::cout << "������� ������� \'�������\':\n";
					//std::cin >> rusT;
					clInput(rusT);

				fprintf(f,"%s %s %s \n",indexT,engT,rusT);
				}
				fclose(f);
				}
				else printf("���������� ������� ����\n"); 
				fclose(f);
					 }

		
						//***********������� ��� ������� �����************
void deleteD()
	 {
FILE* f = fopen("Translater.txt","w"); 
if(f != NULL) 
{
fclose(f);
}
else printf("���������� ������� ����\n"); 
fclose(f);
	 }

//������� ������ ����� �������
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
else std::cout<<"���������� ������� ����\n";
fclose(f);
std::cout << "-------------------\n";
system("pause");
}



	//����� �� �������
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
				//������� ���� for ��� ��������� ������� �������� ��� ������
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
else std::cout<<"���������� ������� ����\n";
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
	std::cout << "*Programm \'Enlish-Russian Translate v1.0 \\�\'*";
	std::cout << "\n********************************************\n";
	//Menu
	std::cout << "*_____________________Menu__________________*\n\n";
	std::cout << "		1-��������\n";
	std::cout << "		2-�����\n";
	std::cout << "		3-�������\n";
	std::cout << "		4-������� ���������� �����\n";
	std::cout << "		0-�����\n";
	std::cout << "\n*___________________________________________*\n";	
	///*************************************************************

	//������� ��� ���� *����������*
	do 
	{
	std::cin >> menu_a;
	//****************1-ADD***********
if (menu_a==1) English_Rus_Translate.add();
	
	//****************2-FIND***********
if (menu_a==2) {
char cWord[5];
std::cout << "������� ��� ������� ��� ������:\n";
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
