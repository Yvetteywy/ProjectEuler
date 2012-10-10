// Find the sum of all the primes below two million.

#include <iostream>
#include <math.h>

#define MAX 2000000

using namespace std;

int main()
{
	// because of this large number,
	// use long instead of int
	long prime = 3;
	long sum = 2;
	long factor = 2;
	while (prime < MAX) {
		long mid = (long)sqrt(prime);
		//cout << "prime = " << prime << ", mid = "<< mid << endl;
		bool isPrime = true;
		while ( factor < mid + 1) {
			if ( prime % factor == 0 ){
				//cout << "	factor = " << factor << endl;
				isPrime = false;
				break;
			}else
				factor ++;
		}
		if (isPrime == true)
			sum += prime;
		prime += 2;
		factor = 2;
	}

	cout << "answer = " << sum << endl;
	return 0;
}
