#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPrime(int number) {
	//Function that checks if a given number is prime or not
	if (number < 2)
		return 0;
	if (number == 2)
		return 1;
	if (number % 2 == 0)
		return 0;
	for (int index = 3; index * index <= number; index++)
		if (number % index == 0)
			return 0;
	return 1;
}

void longestSequence(int n, int v[], int* start, int* end) {
	// Function that returns the start and the end indices of the longest sequence that respects the given property
	int maxLength = 0, currentLength = 0, currentEnd = 0;
	for (int i = 1; i < n; i++)
	{
		if (isPrime(v[i] - v[i - 1]))
		{
			currentLength++;
			currentEnd = i;
		}
		else
			currentLength = 0;
		if (maxLength < currentLength)
		{
			maxLength = currentLength;
			*end = i;
		}
	}
	*start = *end - maxLength;
}

void print(int start, int end, int v[]) {
	// Function that prints the sequence
	char string[100];
	for (int i = start; i <= end; i++)
	{
		sprintf(string, "%d", v[i]);
		printf("%s ", string);
	}
}

int main()
{
	int length = 0, v[100], start = 0, end = 0;

	// read the numbers 
	char s[100];
	scanf("%99[^\n]", s);
	char *p = strtok(s, " ");

	while (p)
	{
		v[length++] = atoi(p);
		p = strtok(NULL, " ");
	}
	// determine the longest sequence
	longestSequence(length, v, &start, &end);
	print(start, end, v);
	getchar();

	//scanf("%d", &length);

	return 0;
}