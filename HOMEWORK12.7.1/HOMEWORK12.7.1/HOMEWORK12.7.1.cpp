#include <iostream>
#include <string>

using namespace std;

bool IsKPeriodic(string data , size_t k)
{
	int* pat = new int[k]; // массив для хранения подстроки которая равна первым k символам от строки data
	for (size_t i = 0; i < k; i++) { pat[i] = data[i]; } // получение подстроки из строки

	if (( data.size() % k ) != 0) // проверка на кратность всей строки числу k
	{
		delete[] pat; // освобождаем память выделенную для хранения подстроки
		return false;
	}
	else
	{
		int cof = 0; // коэффициент увеличивающийся на k(для отсечения проверенной серии символов)

		for (size_t i = 0; i < data.size() / k; i++)
		{
			for (size_t j = 0 + cof; j < k + cof; j++)
			{
				if (data[j] != pat[j - cof])
				{
					delete[] pat; // освобождаем память выделенную для хранения подстроки
					return false;
				}
			}

			cof = cof + k;
		}

		delete[] pat; // освобождаем память выделенную для хранения подстроки
		return true;
	}
}

void PrintIsPeriod(string data , int k)
{
	if (IsKPeriodic(data , k))
		cout << data << " кратна " << k;
	else
		cout << data << " не кратна " << k;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL , "Russian");

	PrintIsPeriod("ABAB" , 2);
	PrintIsPeriod("abcabcabcabc" , 3);
	PrintIsPeriod("AAAA" , 1);
	PrintIsPeriod("NM1ABNM1A" , 4);
	PrintIsPeriod("ABABAABABBABABAABABAABABA" , 5);
	PrintIsPeriod("ACB4512BABACB4512BAB" , 10);

}