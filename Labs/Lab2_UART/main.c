/*
 * GccApplication1.c
 *
 * Created: 7/08/2026 4:05:34 PM
 * Author : bzha931
 */ 

#include <avr/io.h>
#include <stdint.h>

int main(void)
{
    /* Replace with your application code */
	uint16_t primes[62];
	
	uint16_t num, divisor;
	uint8_t primeCount = 0;
	uint8_t isPrime;
	
	for (num = 2; num <= 300; num++)
	{
		isPrime = 1;
		for (divisor = 2; divisor < num; divisor++)
		{
			if (num % divisor == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isPrime)
		{
			primes[primeCount] = num;
			primeCount++;
		}
	}
    while (1) 
    {
    }
	return 0;
}

