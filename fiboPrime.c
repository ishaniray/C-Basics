/* This program interleaves the Fibonacci series with prime numbers (in ascending order) and prints the first 'n' terms.
   For example, if n = 16, the output generated is: 0 2 1 3 1 5 2 7 3 11 5 13 8 17 13 19 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */
void fibo(int*);
void prime(int*);

int main(void)
{
	int n, i, *prevTerms, lastPrime;

	prevTerms = malloc(2 * sizeof(int));    /* array that stores the previous two terms in the Fibonacci sequence */
	lastPrime = 1;    /* variable that keeps track of the last prime number generated */

    /* Initializing prevTerms[] with the first two terms of the Fibonacci series */
	prevTerms[0] = 0;
	prevTerms[1] = 1;

	printf("Enter n: ");
	scanf("%d", &n);
	
	printf("\nFirst %d terms of the series: ", n);

	for(i = 1; i <= n; ++i)    /* for each of the n terms to be generated */
	{
		if(i % 2)    /* if n is odd, generate the next number in the Fibonacci series */
		{
            /* First two terms of the Fibonacci series (i.e., the first and third terms of this particular sequence) are known already, therefore, print them */
			if(i == 1)
				printf("%d ", prevTerms[0]);
			else if(i == 3)
				printf("%d ", prevTerms[1]);
			else    /* compute the next number in the Fibonacci series */
				fibo(prevTerms);
		}
		else    /* n is even; generate the next prime number */
			prime(&lastPrime);
	}
	
	getch();    /* hold the terminal open until a key is pressed */

	return 0;
}

/* Function to generate Fibonacci numbers */
void fibo(int *prevTerms)
{
	int current;

	current = prevTerms[0] + prevTerms[1];    /* the next number in the Fibonacci series is the sum of the previous two numbers */
	
	printf("%d ", current);    /* print the number thus computed */

    /* Reassign values for the next iteration */
	prevTerms[0] = prevTerms[1];
	prevTerms[1] = current;
}

/* Function to generate prime numbers */
void prime(int *lastPrime)
{
	int i, current, primeFlag, sqRoot;
	
	current = *lastPrime + 1;    /* begin searching for the next prime number in the interval that immediately follows the last-generated prime number */

	while(1)
	{
        primeFlag = 1;
        sqRoot = sqrt(current);
        
		for(i = 2; i <= sqRoot; ++i)    /* a number is a prime number if it is not divisible by any number between 2 and its square-root */
		{
			if(!(current % i))    /* the number in the current iteration is not a prime number */
			{
				primeFlag = 0;  
				break;
			}
		}

		if(primeFlag)    /* the number is a prime number */
		{
            printf("%d ", current);    /* print the number */
			*lastPrime = current;    /* set it as the last-generated prime number */
			break;
		}
		else
			current += 1;    /* the number in the current iteration is not prime, therefore move on to the next number */
	}
}
