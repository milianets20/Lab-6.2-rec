#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void create(int* a, const int n, const int i, const int HIGH, const int LOW);
void print(int* a, const int n, const int i);
double calculate(int* a, const int n, const int i, double& serednie_arif,
	int& amount, int& all_i_elements);

int main()
{

	srand(time(NULL));

	int n;
	cout << "A: "; cin >> n;
	int* a = new int[n];
	const int i = 0;
	const int HIGH = 53;
	const int LOW = -17;
	create(a, n, i, HIGH, LOW);
	cout << "a[] = { ";
	print(a, n, i);
	cout << "}" << endl;
	double serednie_arif = 0.;
	int amount = 0;				
	int all_i_elements = 0;		
	cout << "F = " <<
		calculate(a, n, i, serednie_arif, amount, all_i_elements) << endl;
	delete[]a;

	system("pause");
	return 0;
}
void create(int* a, const int n, const int i, const int HIGH, const int LOW)
{
	a[i] = LOW + rand() % (HIGH - LOW + 1);
	if (i < n - 1)
		create(a, n, i + 1, HIGH, LOW);
	else
		return;
}
void print(int* a, const int n, const int i)
{
	cout << a[i] << " ";
	if (i < n - 1)
		print(a, n, i + 1);
	else
		return;
}
double calculate(int* a, const int n, const int i, double& serednie_arif,
	int& amount, int& all_i_elements)
{
	if (i < n)
	{
		bool umova = false;
		if (a[i] % 2 == 0)
		{
			umova = true;
			amount += i;
			all_i_elements++;
		}
		if (umova)
		{
			serednie_arif = (1. * amount) / all_i_elements;
			calculate(a, n, i + 1, serednie_arif, amount, all_i_elements);
		}
		else
			calculate(a, n, i + 1, serednie_arif, amount, all_i_elements);
	}
	else
		return serednie_arif;
}