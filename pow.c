#include <stdio.h>
#include <locale.h>

unsigned power(unsigned g, unsigned k, unsigned m)
{
	unsigned result = 1;
	if (g >= m)
		g %= m;

	while (k)
	{
		if (k & 1)
		{
			result *= g;
			if (result >= m)
				result %= m;
		}
		
		g *= g;	
		if (g >= m)
			g %= m;
		
		k >>= 1;
	}


	return result;
}

int main()
{
	setlocale(LC_ALL, "ru");

	char ch;
	unsigned g, k, m;
	printf("Возведение в степень по модулю");
	
	do
	{
		printf("\n\nВведите целое неотрицательное число: \ng = ");
		scanf_s("%u", &g);

		printf("Введите целую неотрицательную степень: \nk = ");
		scanf_s("%u", &k);

		printf("Введите модуль, больший 1: \nm = ");
		scanf_s("%u", &m);

		unsigned result = power(g, k, m);
		printf("Ответ: %u\n", result);

		printf("Повторить ввод y/n? ");

	} while ((ch = getche()) != 'n');

	return 0;
}