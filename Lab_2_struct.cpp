#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include<math.h>
//Структура "Комплексное число содержит 2 переменные: мнимая и весщественная части числа"
typedef struct{
	float mnimaya_chast;
	float vechestv_chast;
}komplex_number;
//Функции для работы с комплексными числами

komplex_number Init();//Инициализация
komplex_number Read();//Ввод с клавиатуры
void Display (komplex_number A);//Вывод на экран
komplex_number Add(komplex_number a, komplex_number b);//Функция сложения двух комплексных чисел
komplex_number Raz(komplex_number a, komplex_number b);//Функция Вычитания двух комплексных чисел
void compare(komplex_number a, komplex_number b);//Функция Сравнения двух комплексных чисел
int main()
{
	komplex_number A, B;
	komplex_number Sum,Raznost;
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
	puts("A + B =");
	Display(Sum);
	puts("");
	system("pause");

	
	Raznost = Raz(A, B);
	puts("A - B =");
	Display(Raznost);
	puts("");
	system("pause");

	compare(A, B);
	puts("");
	system("pause");

	system("cls");
	puts("Сейчас вы введёте денамическую переменную");
	system("pause");
	komplex_number* Dim;
	Dim = (komplex_number *)malloc(sizeof(komplex_number));
	*Dim = Read();
	Display(*Dim);


}
komplex_number Init()
{
	komplex_number A;
	A = { 2,5 };
	return A;
}
komplex_number Read()
{
	komplex_number A;
	puts("Введите весщественную часть числа");
	scanf("%f", &A.vechestv_chast);
	while (getchar() != '\n');
	system("cls");
	puts("Введите мнимую часть числа");
	scanf("%f", &A.mnimaya_chast);
	while (getchar() != '\n');
	system("cls");
	return A;
}
void Display(komplex_number A)
{
	printf(" %.1fi  + %.1f", A.mnimaya_chast, A.vechestv_chast);
	puts("");
}
komplex_number Add(komplex_number a, komplex_number b)
{
	system("cls");
	komplex_number Summa;
	Summa.mnimaya_chast = a.mnimaya_chast + b.mnimaya_chast;
	Summa.vechestv_chast = a.vechestv_chast + b.vechestv_chast;
	return Summa;
}


komplex_number Raz(komplex_number a, komplex_number b)
{
	system("cls");
	komplex_number Raznost;
	Raznost.mnimaya_chast = a.mnimaya_chast - b.mnimaya_chast;
	Raznost.vechestv_chast = a.vechestv_chast - b.vechestv_chast;
	return Raznost;
}
void compare(komplex_number a, komplex_number b)
{
	system("cls");
	char znak;

	printf("Сравнение чисел %.1fi + %.1f  и  %.1fi + %.1f \nпо модулю\n", a.mnimaya_chast, a.vechestv_chast, b.mnimaya_chast, b.vechestv_chast);
	float amod = sqrt(a.vechestv_chast * a.vechestv_chast + a.mnimaya_chast * a.mnimaya_chast);
	float bmod = sqrt(b.vechestv_chast * b.vechestv_chast + b.mnimaya_chast * b.mnimaya_chast);
	if (amod > bmod)
	{
		znak = '>';
	}
	if (amod < bmod)
	{
		znak = '<';
	}
	if (amod == bmod)
	{
		znak = '=';
	}

	printf("%.1fi + %.1f  %c  %.1fi + %.1f", a.mnimaya_chast, a.vechestv_chast, znak, b.mnimaya_chast, b.vechestv_chast);
}





