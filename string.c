#include "main.h"

/**
 **_strngcopy - copies content
 *@dest: where to copy the string
 *@origin: the origin of the string
 *@n: number of characters to be copied
 *Return: the concatenated string
 */
char *_strngcopy(char *dest, char *origin, int n)
{
	int j, k;
	char *p = dest;

	k = 0;
	while (origin[k] != '\0' && k < n - 1)
	{
		dest[k] = origin[k];
		k++;
	}
	if (k < n)
	{
		j = k;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (p);
}

/**
 **_strngcat - concatenates contents two strings
 *@dest: where the contents of a string are appended
 *@origin: the string to concatenate
 *@n: the number of bytes to be used at most
 *Return: the concatenated string
 */
char *_strngcat(char *dest, char *origin, int n)
{
	int k, j;
	char *c = dest;

	k = 0;
	j = 0;
	while (dest[k] != '\0')
		k++;
	while (origin[j] != '\0' && j < n)
	{
		dest[k] = origin[j];
		k++;
		j++;
	}
	if (j < n)
		dest[k] = '\0';
	return (c);
}
/**
 * _strnglen - returns the string length
 * @s: the string to determine its length
 *
 * Return: the length of the string
 */
int _strnglen(char *str)
{
	int l = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (*str++)
	{
		l++;
	}
	return (l);
}

/**
 * _strngcmp - performs comparison of two strangs.
 * @str1: first string
 * @str2: second string
 *
 * Return: -ve if str1 < str2, +ve if str1 > str2, 0 if str1 == str2
 */
int _strngcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		return (*str1 < *str2 ? -1 : 1);
	}
}
