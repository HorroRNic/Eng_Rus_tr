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
		char indexT[10];
		char engT[30];
		char rusT[50];

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
FILE* f = fopen("Translater.txt","w"); 
if(f != NULL) 
{
	std::cout << "������� ���-�� �������:";
	//std::cin >> nk;


for (i=0;i<nk;i++)
{
clOutput("\n������� ������ ��������:\n");
clInput(indexT);

clOutput("������� ���������� �����:\n");
clInput(engT);

clOutput("������� ������� \'�������\':\n");
clInput(rusT);

fprintf(f,"%s %s %s \n",indexT,engT,rusT);
}
fclose(f);
}
else printf("���������� ������� ����\n"); 
fclose(f);
	 }


void out()
{
clOutput("\n");
 
clOutput("-------------------\n");
FILE* f = fopen("Translater.txt","r");
if(f != NULL) 
{ 
for(i=0;i < nk;i++) 
{fscanf(f,"%s %s %s \n",indexT,engT,rusT); 
puts(indexT);
puts(engT);
puts(rusT);}
fclose(f); 
} 
else std::cout<<"���������� ������� ����\n";
fclose(f);
clOutput("-------------------\n");
system("pause");
}
};
Eng_Rus English_Rus_Translate;




int main()
{
	///
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Header
	std::cout << "\n******************************************\n";
	std::cout << "*Programm \'Enlish-Russian Translate v1.0\'*";
	std::cout << "\n******************************************\n";
	//Menu
	std::cout << "*_____________________Menu__________________*\n\n";
	std::cout << "		1-��������\n";
	std::cout << "		2-�����\n";
	std::cout << "		3-�������\n";
	std::cout << "		0-�����\n";
	std::cout << "\n*___________________________________________*\n";
	
	//������� ��� ���� *����������*
	do (menu_a>0)
	
	std::cin >> menu_a;
if (menu_a==1) English_Rus_Translate.add();
//if (menu_a==2) ;
if (menu_a==3) English_Rus_Translate.out();
	
	while (menu_a==0);

system("pause");
return 0;

}
