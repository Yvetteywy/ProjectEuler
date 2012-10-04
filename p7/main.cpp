// find the 10001st prime

#include <iostream>
#include <math.h>

// the 10001st
#define MAX 10001

using namespace std;


// using a sieve method
bool isPrime(int num)
{
	int factor = 3;
	int till = sqrt( (double)num ) + 1;
	while (factor < till) {
		if ( num % factor == 0 )
			return false;
		factor += 2;
	}
	return true;
}

int main()
{
	int prime_order = 6;
	int cur_prime = 13;
	while ( prime_order < MAX) {
		// since even num will never be prime
		cur_prime += 2;
		if (true == isPrime(cur_prime))
			prime_order ++;
	}

	cout << "answer = " << cur_prime << endl;
	return 0;
}
