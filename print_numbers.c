#include "holberton.h"

/**
 * printhex - function that concatenate a hexadecimal
 * @params: params passed in the elypsis
 * @stocker: Buffer
 * Return: Stocker with the new hexadecimal
 */

char *printhex(va_list params, char *stocker)
{
	int num = va_arg(params, int);
	int count = 0, ref = num, posicion = 0, i, j, len;
	char temp;
	char *p;
	char *a = "0123456789abcdef";
	if (num)
	{
		while (num > 0)
		{
			count++;
			num = num / 16;
		}

		p = malloc(count + 1);

		while (ref > 0)
		{
			p[posicion] = a[ref % 16];
			ref /= 16;
			posicion++;
		}
		p[count] = '\0';

		for (i = 0, j = count - 1; i < count / 2; j--, i++)
		{
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}

		len = _strlen(p);
		_strncat(stocker, p, len);

		return (stocker);
	}
	exit(-1);
}


/**
 * printint - function that adds a int to the string
 * @params: params passed in the elypsis
 * @stocker: buffer
 * Return: string with the new int
 */

char *printint(va_list params, char *stocker)
{
	int value;
	char format[1024];

	if (params)
	{
		value = va_arg(params, int);
		if (value)
		{
			my_itoa(value, format, 10);

			while (value > 0)
			{
				value /= 10;
			}
			strncat(stocker, format, _strlen(format));
		}
		else
		{
			exit(-1);
		}
	}

	return (stocker);
}
