#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include<math.h>
#include <string>
#include <iostream>

using namespace std;
//Структура "Шахматная фигура" содержит 3 переменные: ценность в пешках, название и pawn
typedef struct{
	int value;
	char name[20];
	//Если pawn = true: фигура является пешкой, если false, то не пешкой 
	bool pawn = false;
}chess_figure;
//Функции для работы со структурой

chess_figure Init();//Инициализация
chess_figure Read();//Ввод с клавиатуры
void Display (chess_figure A);//Вывод на экран
chess_figure Add(chess_figure a, chess_figure b);//Функция сложения ценностей фигур
void compare(chess_figure a, chess_figure b);//Сравнение двух фигур
chess_figure pawn_promotion();//Превращение пешки 

char* NAMES[5];
char a1[] = "Пешка";
char a2[] = "Конь";
char a3[] = "Слон";
char a4[] = "Ладья";
char a5[] = "Ферзь";
int main()
{
	NAMES[0] = a1;
	NAMES[1] = a2;
	NAMES[2] = a3;
	NAMES[3] = a4;
	NAMES[4] = a5;
	
	chess_figure A, B;
	chess_figure Sum,Raznost;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	A = Read();

	B=Init();
	
	Display(A);
	Display(B);
	puts("");
	system("pause");

	
	Sum = Add(A, B);
	Display(Sum);
	puts("");
	system("pause");

	compare(A, B);
	puts("");
	system("pause");

	system("cls");
	

	if (A.pawn)
	{
		A = pawn_promotion();
		Display(A);
		system("pause");
	}


	system("cls");
	puts("Сейчас вы введёте динамическую переменную\n");
	system("pause");
	chess_figure* Dim;
	Dim = (chess_figure *)malloc(sizeof(chess_figure));

	(*Dim) = Read();
	Display(*Dim);

	puts("");
	system("pause");

	system("cls");

}
chess_figure Init()
{
	chess_figure A;
	A = { 3,"Конь\n"};
	return A;
}
chess_figure Read()
{
	chess_figure A;
	int vibor;
	puts("Название фигуры");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", i + 1);
		puts(NAMES[i]);
		
	}

	cin >> vibor;
	strcpy(A.name,NAMES[vibor - 1]);
	switch (vibor)
	{
	case 1: {A.value = 1; A.pawn = true; }break;
	case 2: {A.value = 3; }break;
	case 3: {A.value = 3; }break;
	case 4: {A.value = 5; }break;
	case 5: {A.value = 9; }break;
	}
	system("cls");
	return A;
}
void Display(chess_figure A)
{
	puts(A.name);
	printf("\b Ценность %d", A.value);
	puts("");
}
chess_figure Add(chess_figure a, chess_figure b)
{
	system("cls");
	chess_figure Summa;
	Summa.value = a.value + b.value;
	strcpy(Summa.name, a.name);
	strcat(Summa.name, " и ");
	strcat(Summa.name, b.name);
	return Summa;
}



void compare(chess_figure a, chess_figure b)
{
	system("cls");
	char comp[20];

	
	
	if (a.value>b.value)
	{
		strcpy(comp, " Лучше чем ");
	}
	if (a.value < b.value)
	{
		strcpy(comp ," Хуже чем ");
	}
	if (a.value == b.value)
	{
		strcpy(comp," не хуже и не лучше чем ");
	}
	printf("%s %s %s", a.name, comp, b.name);
	
}

chess_figure pawn_promotion()
{
	chess_figure A;
	printf("Ваша пешка дошла до конца доски\nВыбирите фигуру которой она станет\n\n");
	int vibor;
	puts("Название фигуры");
	for (int i = 1; i < 5; i++)
	{
		printf("%d ", i);
		puts(NAMES[i]);

	}
	cin >> vibor;
	strcpy(A.name, NAMES[vibor]);
	switch (vibor)
	{
	
	case 1: {A.value = 3; }break;
	case 2: {A.value = 3; }break;
	case 3: {A.value = 5; }break;
	case 4: {A.value = 9; }break;
	}
	system("cls");
	return A;


}



