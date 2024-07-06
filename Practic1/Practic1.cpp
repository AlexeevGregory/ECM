#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int menu() {
	int ch;
	cout << "Меню:" << endl;
	cout << "1 - Вывод представления типа данного short int" << endl;
	cout << "2 - Вывод представления типа данного double" << endl;
	cout << "3 - Преобразование (циклический сдвиг числа вправо/влево)" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "> ";
	cin >> ch;
	return ch;
}
void output_short_int(short int value) {
	int lines = sizeof(short int) * 8;
	int mask = 1 << (lines - 1);
	for (int i = 1; i <= lines; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i % lines - 1 == 0)
		{
			putchar(' ');
		}
	}
}
void output_double(double b) {
	union {
		char value[];
		double a;
	};
	a = b;
	int lines = sizeof(double) * 8, mask = 1;
	mask <<= (lines - 1);
	for (int j = (lines/8)-1; j >= 0; j--)
	{
		for (int i = 0; i < lines/8; i++)
		{
			putchar(value[j] & mask ? '1' : '0');
			value[j] <<= 1;
			if ((i == 0) and (j == 7))
			{
				putchar(' ');
			}
			if ((i == 3) and (j == 6))
			{
				putchar(' ');
			}
		}
	}
}
void First_Question() {
	short int value;
	cout << "Введите число: ";
	cin >> value;
	output_short_int(value);
}
void Second_Question() {
	double a;
	cout << "Введите число: ";
	cin >> a;
	output_double(a);
}
template <typename T> T shift_right(T a, int discharge) {
	union {
		char arr[];
		T val;
	};
	val = a;
	char mask = 1;
	int valBin[sizeof(T) * 8];
	for (int i = 0; i < sizeof(T); i++) {
		for (int j = 0; j < sizeof(char) * 8; j++) {
			valBin[sizeof(T) * 8 - 1 - (i * 8 + j)] = mask & arr[i];
			arr[i] >>= 1;
		}
	}
	for (int i = 0; i < discharge; i++) {
		int start = valBin[sizeof(T) * 8 - 1];
		for (int j = sizeof(T) * 8 - 1; j > 0; j--) {
			valBin[j] = valBin[j - 1];
		}
		valBin[0] = start;
		for (int k = 0; k < sizeof(T) * 8; k++) {
			cout << valBin[k];
		}
		cout << endl;
	}
	for (int i = 0; i < sizeof(T); i++) {
		arr[i] = 0;
		for (int j = 7; j >= 0; j--) {
			arr[i] += valBin[sizeof(T) * 8 - 1 - i * 8 - j] * pow(2, j);
		}
	}
	cout << "обычное представление числа: " << val << endl;
	cout << "двоичное представление числа: ";
	if (sizeof(T) == sizeof(short int)) output_short_int(val);
	else output_double(val);
	cout << endl;

	return val;
}
template <typename T> T shift_left(T a, int discharge) {
	union
	{
		char arr[];
		T val;
	};
	char mask = 1;
	val = a;
	int valBin[sizeof(T) * 8];
	for (int i = 0; i < sizeof(T); i++) {
		for (int j = 0; j < sizeof(char) * 8; j++) {
			valBin[sizeof(T) * 8 - 1 - (i * 8 + j)] = mask & arr[i];
			arr[i] >>= 1;
		}
	}
	for (int i = 0; i < discharge; i++) {
		int start = valBin[0];
		for (int j = 0; j < sizeof(T) * 8 - 1; j++) {
			valBin[j] = valBin[j + 1];
		}
		valBin[sizeof(T) * 8 - 1] = start;
		for (int k = 0; k < sizeof(T) * 8; k++) {
			cout << valBin[k];
		}
		cout << endl;
	}
	for (int i = 0; i < sizeof(T); i++) {
		arr[i] = 0;
		for (int j = 7; j >= 0; j--) {
			arr[i] += valBin[sizeof(T) * 8 - 1 - i * 8 - j] * pow(2, j);
		}
	}
	cout << "обычное представление числа: " << val << endl;
	cout << "двоичное представление числа: ";
	if (sizeof(T) == sizeof(short int)) output_short_int(val);
	else output_double(val);
	cout << endl;
	return val;
}
void Third_Question_Int() {
	int ch, discharge;
	short int value;
	cout << endl;
	cout << "1 - циклический сдвиг вправо" << endl;
	cout << "2 - циклический сдвиг влево" << endl;
	cout << "> ";
	cin >> ch;
	cout << "Введите значение числа и число для поразрядного сдвига: ";
	cin >> value;
	cin >> discharge;
	switch (ch)
	{
	case 1:
		value = shift_right(value, discharge);
		break;
	case 2:
		value = shift_left(value, discharge);
		break;
	default:
		break;
	}
}
void Third_Question_Double() {
	int ch, discharge;
	double value;
	cout << endl;
	cout << "1 - циклический сдвиг вправо" << endl;
	cout << "2 - циклический сдвиг влево" << endl;
	cout << "> ";
	cin >> ch;
	cout << "Введите значение числа и число для поразрядного сдвига: ";
	cin >> value;
	cin >> discharge;
	switch (ch)
	{
	case 1:
		value = shift_right(value, discharge);
		break;
	case 2:
		value = shift_left(value, discharge);
		break;
	default:
		break;
	}
}
void Third_Question() {
	int ch;
	cout << endl << "Укажите с каким типом данных пойдет работа:" << endl;
	cout << "1 - целое число" << endl;
	cout << "2 - число с плавающей точкой" << endl;
	cout << "> ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		Third_Question_Int();
		break;
	case 2:
		Third_Question_Double();
		break;
	default:
		break;
	}
}
int main()
{
    setlocale(0, "");
	int ch;
	while (true) {
		ch = menu();
		switch (ch)
		{
		case(1):
			First_Question();
			break;
		case(2):
			Second_Question();
			break;
		case(3):
			Third_Question();
			break;
		case(0):
			return 0;
		default:
			cout << "Введено неправильное значение";
			break;
		}
		cout << endl;
	}
}